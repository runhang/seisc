#include "stdafx.h"
#include "EvtFileProcessing.h"


EvtFileProcessing::EvtFileProcessing()
{
	cout << "EvtFileProessing processing..." << endl;
}


EvtFileProcessing::~EvtFileProcessing()
{
}

void EvtFileProcessing::setEvtFileName(string & value) {
	evtFileName = value;
}

string EvtFileProcessing::getEvtFileName() {
	return evtFileName;
}


void EvtFileProcessing::readData(const int&  time_length) {
	if (singleStations.size() > 1) {
		//singleStations.clear(); //清空vector的内容，但不回收内存
		singleStations.swap(vector<SingleStation>()); //回收内存
	}
	ifstream ifs(evtFileName, ios::binary | ios::in); //只读模式,二进制文件读入
														 //ifs.seekg(0, ios::beg);  //ios::beg文件开头。 ios::cur文件当前位置  ios::end文件结尾
														 //evtFileHeader.readHeader(ifs); //读入文件头
	//string fileFlag = evtFileHeader.getEventFileFlag();

	//readStations(ifs);
	evtFileHeader.readHeader(ifs); //读入文件头
	
	readStations(ifs);

	readWaveData(ifs, time_length);  
	//cout << toStringWaveData();
	
}


void EvtFileProcessing::readAllData() {
	//host = parent
	if (singleStations.size() > 1) {
		//singleStations.clear(); //清空vector的内容，但不回收内存
		singleStations.swap(vector<SingleStation>()); //回收内存
  	}

	//如果EvtFileName文件为空
	//if () {}

	//如果EvtFileName文件不存在
	//if() {}

	ifstream ifs(evtFileName, ios::binary|ios::in, 0); //只读模式,二进制文件读入
	ifs.seekg(0, ios::beg);  //ios::beg文件开头。 ios::cur文件当前位置  ios::end文件结尾
	evtFileHeader.readHeader(ifs); //读入文件头
	string fileFlag = evtFileHeader.getEventFileFlag();
	
	readStations(ifs);
	
	readWaveData(ifs, 20000);//读取点数最大为20000
	
	ifs.close();

	isEvtFileOpen = true;

}

string EvtFileProcessing::toStringForStationNumber(int begin, int stationNumber) {
	stringstream ss;
	for (int i = begin; i < stationNumber; i++) {
		//ss << singleStations[i].toStringAllChangesData();//.toString();
		SingleStation sst = singleStations[i];
		int channelNumber = sst.getChannelNumber();
		SingleChannel sc = singleStations[i].getSingleChannels()[0];
		//stringstream ss;
		//ss << "index\t样本值\t样本值\t样本值\n";
		int waveLength = sc.getWaveData().size();

		if ((sst.getDataUsableFlags().size() * 0.75) < (sst.getBadDataCount())) { //异常点超过取出的数的0.75，不再保存该台站信息
		//0：数据正常， 1：数据有异
			continue;
		}
		for (int j = 0; j < channelNumber; j++)
		{
			if (waveLength < sst.getSingleChannels()[j].getWaveData().size())
				waveLength = sst.getSingleChannels()[j].getWaveData().size();
		}
		
		for (int j = 0; j < channelNumber; j++)
		{
			SingleChannel sc = sst.getSingleChannels()[j]; //第几通道
			int len = sc.getWaveData().size();
			if (len < 5050) {
				continue;
			}
			else {
				ss << sst.getStationName() << "-" << sc.getChannelName();  //序列标出通道
				//ss << "\t" << sst.getStationLatitude() << "\t" << sst.getStationLongitude();
				//cout << sc.getStrForTxt().c_str();
				ss << sc.getStrForTxt(); // 代替下面的for循环，前面已经有一个“\r”
										 /*
										 for (int m = 0; m < waveLength; m++)
										 {
										 //ss << (m + 1) << "\t"; //序号
										 ss << "\t" << sc.getWaveData()[m]; // 本通道波形数据
										 }*/
				ss << "\n";
			}
		}

	}
	string str = ss.str();
	ss.clear();
	return str;
}

void EvtFileProcessing::writeData(TxtWrite& tw) {
	
	int stationNumber = evtFileHeader.getNumberStation();
	int beforeStation = stationNumber / 2;
	string str = toStringForStationNumber(0, beforeStation);
	tw.write(str);
	str = toStringForStationNumber(beforeStation, stationNumber);
	tw.write(str);
}

vector<double> & EvtFileProcessing::getSingleWave(string & fileName, int & stationNumber, int & channelNumber) {
	vector<double> waves;

	//DateTime 
	string recordOriginTime;
	Int32 recordLength, samplingRate;
	int i(0), j(0), k(0);
	if (evtFileName.compare(fileName) == 0 && isEvtFileOpen) {
		for (i = 0; i != singleStations[stationNumber].getSingleChannels()[channelNumber].getWaveData().size(); i++) {
			waves.push_back((double)singleStations[stationNumber]
				.getSingleChannels()[channelNumber].getWaveData()[i]);
		}
	}
	else {
		evtFileName = fileName;
		ifstream ifs(evtFileName, ios::binary | ios::in, 0);
		//ifs.seekg(0, ios::cur);

		evtFileHeader.readHeader(ifs);
		readStations(ifs);

		return waves;

	}
}

//
string EvtFileProcessing::toString() {
	stringstream ss;
	ss << evtFileHeader.toString();

	for (int i = 0; i < evtFileHeader.getNumberStation(); i++) {
		ss << singleStations[i].toStringAllChangesData();//.toString();
	}

	return ss.str();
}


string EvtFileProcessing::toStringWaveData() {
	stringstream ss;

	for (int i = 0; i < evtFileHeader.getNumberStation(); i++) {
		//ss << singleStations[i].toStringAllChangesData();//.toString();
		SingleStation sst = singleStations[i];
		int channelNumber = sst.getChannelNumber();
		SingleChannel sc = singleStations[i].getSingleChannels()[0];
		//stringstream ss;
		//ss << "index\t样本值\t样本值\t样本值\n";
		int waveLength = sc.getWaveData().size();
		int ss_value = sst.getBadDataCount();
		int du_value = sst.getDataUsableFlags().size();
		if ((sst.getDataUsableFlags().size() * 0.8) < (sst.getBadDataCount())) { //异常点超过取出的数的0.8，不再保存该台站信息
			//0：数据正常， 1：数据有异
			continue;
		}
		for (int j = 0; j < channelNumber; j++)
		{
			if (waveLength < sst.getSingleChannels()[j].getWaveData().size())
				waveLength = sst.getSingleChannels()[j].getWaveData().size();
		}
		for (int j = 0; j < channelNumber; j++)
		{
			SingleChannel sc = sst.getSingleChannels()[j]; //第几通道

			string str = sc.getStrForTxt();
			int len = sc.getWaveData().size();
			if (len < 7000) {
				continue;
			}
			else {
				ss << sst.getStationName() << "-" << sc.getChannelName() << "\t";  //序列标出通道
				ss << sst.getStationLatitude() << "\t" << sst.getStationLongitude();
				//cout << sc.getStrForTxt().c_str();
				ss << str; // sc.getStrForTxt(); // 代替下面的for循环
				/*
				for (int m = 0; m < waveLength; m++)
				{
					//ss << (m + 1) << "\t"; //序号
					ss << "\t" << sc.getWaveData()[m]; // 本通道波形数据
				}*/
				ss << "\n";
			}
		}
	}
	string str = ss.str();ss.clear();
	return str;
}

//private
void EvtFileProcessing::readStations(ifstream & ifs) {
	//List<SingleStation> Stations = new List<SingleStation>();
	for (int i = 0; i < evtFileHeader.getNumberStation(); i++)
	{
		SingleStation singleStation; // = new SingleStation();
		singleStation.read(ifs);
		singleStations.push_back(singleStation);
	}

}

//
void EvtFileProcessing::readWaveData(ifstream & ifs, int time_length) {
	//?
	//?
	int recordLength = evtFileHeader.getRecordLength();////////////////////////////////
	
	if (time_length == 0) {  //read_length==0,全序列读取
		time_length = recordLength;
	}
	if (recordLength < time_length) {////////////////////////////////
		time_length = recordLength;///////////////////////////////////
	}//////////////////////////////
	for (int i = 0; i < recordLength; i++) {
		for (int j = 0; j < evtFileHeader.getNumberStation(); j++) {
			if (i >= time_length) {  //如果超过了记录长度，跳过
				if (recordLength > time_length) {
					int step = (recordLength - time_length) * (4 + singleStations[j].getDigitRate() * 12);
					ifs.seekg(step, ios::cur);
					continue;
				}
			}
			singleStations[j].readData(ifs);
		}
	}
	
}

void EvtFileProcessing::clear() {
	for (int i = 0; i < evtFileHeader.getNumberStation(); i++) {
		singleStations[i].clear();
	}
	singleStations.swap(vector<SingleStation>());
}


