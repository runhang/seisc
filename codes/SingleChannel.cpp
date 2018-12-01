#include "stdafx.h"
#include "SingleChannel.h"

using namespace std;

SingleChannel::SingleChannel(string & fileName)
{
	continuePointSec = 0; //��ʼ������������Ϊ0
	channelName = new char[12 + 1];  //|   ͨ������   |  �ַ���  |   12   |    |
	eventFileName = fileName;
	shortTemp = new char[2 + 1]; // short����
	intTemp = new char[4 + 1];
	floatTemp = new char[4 + 1];
	////////////////////////////////////////////////////////////////////////////
	
	channelName[12] = '\0';     //|   ͨ������   |  �ַ���  |   12   |    | 
	shortTemp[2] = '\0'; // short����
	intTemp[4] = '\0';  //����
	floatTemp[4] = '\0';  //����
}

SingleChannel::SingleChannel(const SingleChannel & singleChannel)
{
	channelName = new char[12 + 1];     //|   ͨ������   |  �ַ���  |   12   |    |
	shortTemp = new char[2 + 1]; // short����
	intTemp = new char[4 + 1];
	floatTemp = new char[4 + 1];

	//setEventFileName(singleChannel.getEv;

	channelName[12] = '\0';     //|   ͨ������   |  �ַ���  |   12   |    | 
	shortTemp[2] = '\0'; // short����
	intTemp[4] = '\0';  //����
	floatTemp[4] = '\0';  //����
	setEventFileName(singleChannel.getEventFileName());
	setChannelName(singleChannel.getChannelName().c_str());    //[12] = '\0'; //|   ͨ������   |  �ַ���  |   12   |    | 
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
	setChannelName(singleChannel.getChannelName().c_str());    //[12] = '\0'; //|   ͨ������   |  �ַ���  |   12   |    | 
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
	delete[] channelName;  //[12] = '\0';     //|   ͨ������   |  �ַ���  |   12   |    | 
	delete[] shortTemp;   //[2] = '\0'; // short����
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
	int deprecate_num(0); //���õ����
	float pre_point_temp = 0; //��һ����Ļ���ֵ
	float d(0);
	if (Is4Bytes){
		for (int i = 0; i < Count; i++){//20000����ʱ��ֹͣ����
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
		if (waveData.size() < 6650) { //����5000��������ǰ��ֵ��Ҫ
			strForTxt.swap(string()); //���string
			waveData.swap(vector<float>());
			this->continuePointSec = 0;  //���¿�ʼ����
		}else {//��6100������������Ĳ�Ҫ
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
int deprecate_num(0); //���õ����
float pre_point_temp = 0; //��һ����Ļ���ֵ
if (Is4Bytes){
for (int i = 0; i < Count; i++){//20000����ʱ��ֹͣ����
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
	
	ss << "��ͨ��������Ϣ : \n"
	   << "ͨ������ : " << getChannelName() << "\n"          //|   ͨ������      |  �ַ���  |   12      |                             |  
	   << "ͨ����� : " << (getChannelNumber() + 1) << "\n"   //|   ͨ�����      |  ����    |   4       |                             |  
	   << "�������� : " << getGain() << "\n"                 //|   ��������      |  ����    |   4       |                             |  
	   << "��Ӧ���� : " << getResponseOrder() << "\n"        //|   ��Ӧ����      |  ����    |   4       |                             |  
	   << "��Ӧ���� : " << getResponseType() << "\n"         //|   ��Ӧ����      |  ����    |   4       |                             |  
	   << "Ƶ����Ŀ : " << getFrequenceNumber() << "\n";      //|   Ƶ����Ŀ      |  ����    |   4       |                             |  
	 
	ss<< "\n��ͨ���������� --- \n"
	  << "���������\t����ֵ\n";

	
	//for (vector<float>::iterator it = waveData.begin(); it != waveData.end(); it++, i++)
	for (int i = 0; i < waveData.size(); i++)
	{
		ss<<"\t"
		  <<(i + 1) + "\t\t"
		  <<waveData[i]
		  <<"\n";         // ��ͨ����������
	}
	ss<<"\n";
	return ss.str();
}

string SingleChannel::toStringOnlyChannel() {
	stringstream ss;
	ss << "ͨ������ : " << getChannelName() << "\n"            //|   ͨ������   |  �ַ��� |   12   |                             |  
		<< "ͨ����� : " << (getChannelNumber() + 1) << "\n"   //|   ͨ�����   |  ����   |   4    |                             |  
		<< "�������� : " << getGain() << "\n"                  //|   ��������   |  ����   |   4    |                             |  
		<< "��Ӧ���� : " << getResponseOrder() << "\n"         //|   ��Ӧ����   |  ����   |   4    |                             |  
		<< "��Ӧ���� : " << getResponseType() << "\n"          //|   ��Ӧ����   |  ����   |   4    |                             |  
		<< "Ƶ����Ŀ : " << getFrequenceNumber() << "\n";       //|   Ƶ����Ŀ   |  ����   |   4    |                             |  
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
			<< "\n";         // ��ͨ����������
	}
	ss << "\n";
	return ss.str();
	return ss.str();
}

