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
		//singleStations.clear(); //���vector�����ݣ����������ڴ�
		singleStations.swap(vector<SingleStation>()); //�����ڴ�
	}
	ifstream ifs(evtFileName, ios::binary | ios::in); //ֻ��ģʽ,�������ļ�����
														 //ifs.seekg(0, ios::beg);  //ios::beg�ļ���ͷ�� ios::cur�ļ���ǰλ��  ios::end�ļ���β
														 //evtFileHeader.readHeader(ifs); //�����ļ�ͷ
	//string fileFlag = evtFileHeader.getEventFileFlag();

	//readStations(ifs);
	evtFileHeader.readHeader(ifs); //�����ļ�ͷ
	
	readStations(ifs);

	readWaveData(ifs, time_length);  
	//cout << toStringWaveData();
	
}


void EvtFileProcessing::readAllData() {
	//host = parent
	if (singleStations.size() > 1) {
		//singleStations.clear(); //���vector�����ݣ����������ڴ�
		singleStations.swap(vector<SingleStation>()); //�����ڴ�
  	}

	//���EvtFileName�ļ�Ϊ��
	//if () {}

	//���EvtFileName�ļ�������
	//if() {}

	ifstream ifs(evtFileName, ios::binary|ios::in, 0); //ֻ��ģʽ,�������ļ�����
	ifs.seekg(0, ios::beg);  //ios::beg�ļ���ͷ�� ios::cur�ļ���ǰλ��  ios::end�ļ���β
	evtFileHeader.readHeader(ifs); //�����ļ�ͷ
	string fileFlag = evtFileHeader.getEventFileFlag();
	
	readStations(ifs);
	
	readWaveData(ifs, 20000);//��ȡ�������Ϊ20000
	
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
		//ss << "index\t����ֵ\t����ֵ\t����ֵ\n";
		int waveLength = sc.getWaveData().size();

		if ((sst.getDataUsableFlags().size() * 0.75) < (sst.getBadDataCount())) { //�쳣�㳬��ȡ��������0.75�����ٱ����̨վ��Ϣ
		//0������������ 1����������
			continue;
		}
		for (int j = 0; j < channelNumber; j++)
		{
			if (waveLength < sst.getSingleChannels()[j].getWaveData().size())
				waveLength = sst.getSingleChannels()[j].getWaveData().size();
		}
		
		for (int j = 0; j < channelNumber; j++)
		{
			SingleChannel sc = sst.getSingleChannels()[j]; //�ڼ�ͨ��
			int len = sc.getWaveData().size();
			if (len < 5050) {
				continue;
			}
			else {
				ss << sst.getStationName() << "-" << sc.getChannelName();  //���б��ͨ��
				//ss << "\t" << sst.getStationLatitude() << "\t" << sst.getStationLongitude();
				//cout << sc.getStrForTxt().c_str();
				ss << sc.getStrForTxt(); // ���������forѭ����ǰ���Ѿ���һ����\r��
										 /*
										 for (int m = 0; m < waveLength; m++)
										 {
										 //ss << (m + 1) << "\t"; //���
										 ss << "\t" << sc.getWaveData()[m]; // ��ͨ����������
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
		//ss << "index\t����ֵ\t����ֵ\t����ֵ\n";
		int waveLength = sc.getWaveData().size();
		int ss_value = sst.getBadDataCount();
		int du_value = sst.getDataUsableFlags().size();
		if ((sst.getDataUsableFlags().size() * 0.8) < (sst.getBadDataCount())) { //�쳣�㳬��ȡ��������0.8�����ٱ����̨վ��Ϣ
			//0������������ 1����������
			continue;
		}
		for (int j = 0; j < channelNumber; j++)
		{
			if (waveLength < sst.getSingleChannels()[j].getWaveData().size())
				waveLength = sst.getSingleChannels()[j].getWaveData().size();
		}
		for (int j = 0; j < channelNumber; j++)
		{
			SingleChannel sc = sst.getSingleChannels()[j]; //�ڼ�ͨ��

			string str = sc.getStrForTxt();
			int len = sc.getWaveData().size();
			if (len < 7000) {
				continue;
			}
			else {
				ss << sst.getStationName() << "-" << sc.getChannelName() << "\t";  //���б��ͨ��
				ss << sst.getStationLatitude() << "\t" << sst.getStationLongitude();
				//cout << sc.getStrForTxt().c_str();
				ss << str; // sc.getStrForTxt(); // ���������forѭ��
				/*
				for (int m = 0; m < waveLength; m++)
				{
					//ss << (m + 1) << "\t"; //���
					ss << "\t" << sc.getWaveData()[m]; // ��ͨ����������
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
	
	if (time_length == 0) {  //read_length==0,ȫ���ж�ȡ
		time_length = recordLength;
	}
	if (recordLength < time_length) {////////////////////////////////
		time_length = recordLength;///////////////////////////////////
	}//////////////////////////////
	for (int i = 0; i < recordLength; i++) {
		for (int j = 0; j < evtFileHeader.getNumberStation(); j++) {
			if (i >= time_length) {  //��������˼�¼���ȣ�����
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


