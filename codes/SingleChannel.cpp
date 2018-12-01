#include "stdafx.h"
#include "SingleChannel.h"

using namespace std;

SingleChannel::SingleChannel(string & fileName)
{
	continuePointSec = 0; //初始化连续点秒数为0
	channelName = new char[12 + 1];  //|   通道名称   |  字符串  |   12   |    |
	eventFileName = fileName;
	shortTemp = new char[2 + 1]; // short缓存
	intTemp = new char[4 + 1];
	floatTemp = new char[4 + 1];
	////////////////////////////////////////////////////////////////////////////
	
	channelName[12] = '\0';     //|   通道名称   |  字符串  |   12   |    | 
	shortTemp[2] = '\0'; // short缓存
	intTemp[4] = '\0';  //缓存
	floatTemp[4] = '\0';  //缓存
}

SingleChannel::SingleChannel(const SingleChannel & singleChannel)
{
	channelName = new char[12 + 1];     //|   通道名称   |  字符串  |   12   |    |
	shortTemp = new char[2 + 1]; // short缓存
	intTemp = new char[4 + 1];
	floatTemp = new char[4 + 1];

	//setEventFileName(singleChannel.getEv;

	channelName[12] = '\0';     //|   通道名称   |  字符串  |   12   |    | 
	shortTemp[2] = '\0'; // short缓存
	intTemp[4] = '\0';  //缓存
	floatTemp[4] = '\0';  //缓存
	setEventFileName(singleChannel.getEventFileName());
	setChannelName(singleChannel.getChannelName().c_str());    //[12] = '\0'; //|   通道名称   |  字符串  |   12   |    | 
	setChannelNumber(singleChannel.getChannelNumber());
	setFrequenceNumber(singleChannel.getFrequenceNumber());
	setGain(singleChannel.getGain());
	setResonseOrder(singleChannel.getResponseOrder());
	setResponseType(singleChannel.getResponseType());
	setWaveData(singleChannel.getWaveData());
	setStrForTxt(singleChannel.getStrForTxt());
	setContinuePointSec(singleChannel.getContinuePointSec());
	
}

void SingleChannel::operator=(const SingleChannel & singleChannel) {
	setEventFileName(singleChannel.getEventFileName());
	setChannelName(singleChannel.getChannelName().c_str());    //[12] = '\0'; //|   通道名称   |  字符串  |   12   |    | 
	setChannelNumber(singleChannel.getChannelNumber());
	setFrequenceNumber(singleChannel.getFrequenceNumber());
	setGain(singleChannel.getGain());
	setResonseOrder(singleChannel.getResponseOrder());
	setResponseType(singleChannel.getResponseType());
	setWaveData(singleChannel.getWaveData());
	setStrForTxt(singleChannel.getStrForTxt());
	setContinuePointSec(singleChannel.getContinuePointSec());
}

SingleChannel::~SingleChannel()
{
	delete[] channelName;  //[12] = '\0';     //|   通道名称   |  字符串  |   12   |    | 
	delete[] shortTemp;   //[2] = '\0'; // short缓存
	delete[] intTemp;     //[4] = '\0';
	delete[] floatTemp;   //[4] = '\0';
	
}

//set and get function
//set function
void SingleChannel::setChannelName(const char * value) {
	int len = strlen(value);
	
	len = (12 < len) ? 12 : len;
	channelName[len] = '\0';
	for (int i = 0; i < len; i++) {
		channelName[i] = value[i];
	}
}

void SingleChannel::setChannelNumber(const Int32 & value) {
	channelNumber = value;
}

void SingleChannel::setGain(const float & value) {
	gain = value;
}

void SingleChannel::setResonseOrder(const Int32 & value) {
	responseOrder = value;
}

void SingleChannel::setResponseType(const Int32 & value) {
	responseType = value;
}

void SingleChannel::setFrequenceNumber(const Int32 & value) {
	frequenceNumber = value;
}

void SingleChannel::setWaveData(const vector<float> & value) {
	waveData.assign(value.begin(), value.end());
}

void SingleChannel::setEventFileName(const string & value) {
	eventFileName.assign(value);
}

void SingleChannel::setStrForTxt(const string & value) {
	strForTxt.assign(value);
}

void SingleChannel::setContinuePointSec(const int &value){
	continuePointSec = value;
}

// Get function
string SingleChannel::getEventFileName()const {
	return eventFileName;
}

string SingleChannel::getChannelName() const {
	return string(channelName);
}

Int32 SingleChannel::getChannelNumber()const {
	return channelNumber;
}

float SingleChannel::getGain()const {
	return gain;
}

Int32 SingleChannel::getResponseOrder()const {
	return responseOrder;
}

Int32 SingleChannel::getResponseType()const {
	return responseType;
}

Int32 SingleChannel::getFrequenceNumber()const {
	return frequenceNumber;
}

vector<float> SingleChannel::getWaveData()const {
	return waveData;
}

string SingleChannel::getStrForTxt() const {
	return strForTxt;
}

int SingleChannel::getContinuePointSec() const {
	return continuePointSec;
}

// get function end

void SingleChannel::read(ifstream & ifs) {

	ifs.read(channelName, 12);  // read Channel

	ifs.read(intTemp, 4);
	channelNumber = MathUtils::toInt(intTemp);
	
	ifs.read(floatTemp, 4);
	gain = MathUtils::toFloat(floatTemp);

	ifs.read(intTemp, 4);
	responseOrder = MathUtils::toInt(intTemp);

	ifs.read(intTemp, 4);
	responseType = MathUtils::toInt(intTemp);

	ifs.read(intTemp, 4);
	frequenceNumber = MathUtils::toInt(intTemp);

	ifs.seekg(12280, ios::cur);
}

void SingleChannel::readData(ifstream & ifs, int Count, bool Is4Bytes)
{
	stringstream ss;
	int deprecate_num(0); //弃用点点数
	float pre_point_temp = 0; //上一个点的缓存值
	float d(0);
	if (Is4Bytes){
		for (int i = 0; i < Count; i++){//20000个点时候，停止读数
			//float d = binReader.ReadInt32();
			//waveData.assign(d);
			
			ifs.read(intTemp, 4);
			
			d = MathUtils::toInt(intTemp);

			if (abs(d - pre_point_temp) < 1) {
				deprecate_num++;
			}
			pre_point_temp = d;

			waveData.push_back(d);
			ss << "\t" << d;
			//delete shortTemp;
		}
	}else{
		for (int i = 0; i < Count; i++){
			//float d = ifs.ReadInt16();
			//WaveData.Add(d);
			ifs.read(floatTemp, 4);
			
			d = MathUtils::toShort(floatTemp);

			if (abs(d - pre_point_temp) < 1) {
				deprecate_num++;
			}
			pre_point_temp = d;

			waveData.push_back(d);
			ss << "\t" << d;
		}
	}//end

	if (deprecate_num < 36) {
		strForTxt.append(ss.str().c_str());
		this->continuePointSec = 0;
	}else {
		if (waveData.size() < 6650) { //不够5000个点数，前面值不要
			strForTxt.swap(string()); //清空string
			waveData.swap(vector<float>());
			this->continuePointSec = 0;  //重新开始记数
		}else {//够6100个点数，后面的不要
			this->continuePointSec ++;
		}

	}
	//cout << ss.str() << endl;
	
	//cout << strForTxt << endl;
	//ss.clear();
}

void SingleChannel::clear() {
	if (waveData.size() >= 1) {
		waveData.clear();
	}
}

/*
void SingleChannel::readData(ifstream & ifs, int Count, bool Is4Bytes)
{
stringstream ss;
int deprecate_num(0); //弃用点点数
float pre_point_temp = 0; //上一个点的缓存值
if (Is4Bytes){
for (int i = 0; i < Count; i++){//20000个点时候，停止读数
//float d = binReader.ReadInt32();
//waveData.assign(d);

ifs.read(intTemp, 4);

float d = MathUtils::toInt(intTemp);

if ((d - pre_point_temp) < 0) {
deprecate_num++;
}
pre_point_temp = d;

waveData.push_back(d);
ss << "\t" << d;
//delete shortTemp;
}
}else{
for (int i = 0; i < Count; i++){
//float d = ifs.ReadInt16();
//WaveData.Add(d);
ifs.read(floatTemp, 4);

float d = MathUtils::toShort(floatTemp);

if ((d - pre_point_temp) < 1) {
deprecate_num++;
}
pre_point_temp = d;

waveData.push_back(d);
ss << "\t" << d;
}
}//end


}
//cout << ss.str() << endl;

//cout << strForTxt << endl;
//ss.clear();
}
*/

string SingleChannel::toString() {
	stringstream ss;
	
	ss << "本通道基本信息 : \n"
	   << "通道名称 : " << getChannelName() << "\n"          //|   通道名称      |  字符串  |   12      |                             |  
	   << "通道序号 : " << (getChannelNumber() + 1) << "\n"   //|   通道编号      |  整型    |   4       |                             |  
	   << "增益因子 : " << getGain() << "\n"                 //|   增益因子      |  浮点    |   4       |                             |  
	   << "响应阶数 : " << getResponseOrder() << "\n"        //|   响应阶数      |  整型    |   4       |                             |  
	   << "响应类型 : " << getResponseType() << "\n"         //|   响应类型      |  整型    |   4       |                             |  
	   << "频率数目 : " << getFrequenceNumber() << "\n";      //|   频率数目      |  整型    |   4       |                             |  
	 
	ss<< "\n本通道波形数据 --- \n"
	  << "样本点序号\t样本值\n";

	
	//for (vector<float>::iterator it = waveData.begin(); it != waveData.end(); it++, i++)
	for (int i = 0; i < waveData.size(); i++)
	{
		ss<<"\t"
		  <<(i + 1) + "\t\t"
		  <<waveData[i]
		  <<"\n";         // 本通道波形数据
	}
	ss<<"\n";
	return ss.str();
}

string SingleChannel::toStringOnlyChannel() {
	stringstream ss;
	ss << "通道名称 : " << getChannelName() << "\n"            //|   通道名称   |  字符串 |   12   |                             |  
		<< "通道序号 : " << (getChannelNumber() + 1) << "\n"   //|   通道编号   |  整型   |   4    |                             |  
		<< "增益因子 : " << getGain() << "\n"                  //|   增益因子   |  浮点   |   4    |                             |  
		<< "响应阶数 : " << getResponseOrder() << "\n"         //|   响应阶数   |  整型   |   4    |                             |  
		<< "响应类型 : " << getResponseType() << "\n"          //|   响应类型   |  整型   |   4    |                             |  
		<< "频率数目 : " << getFrequenceNumber() << "\n";       //|   频率数目   |  整型   |   4    |                             |  
	return ss.str();
}


string SingleChannel::toWaveDataOnlyCHannelToFile() {
	stringstream ss;
	ss << this->getChannelName();
	for (int i = 0; i < waveData.size(); i++)
	{
		ss << "\t"
			<< (i + 1) + "\t\t"
			<< waveData[i]
			<< "\n";         // 本通道波形数据
	}
	ss << "\n";
	return ss.str();
	return ss.str();
}

