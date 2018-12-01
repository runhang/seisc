#include "stdafx.h"
#include "SingleStation.h"




SingleStation::SingleStation()
{
	stationName = new char[20 + 1];

	stationName[20] = '\0';//20
	digitType[10] = '\0';  //10
	transferEquipment[12] = '\0';//12
	clockEquipment[12] = '\0'; //12
	seimicMeterName[8] = '\0';//8
}

SingleStation::SingleStation(const SingleStation & singleStation){
	stationName = new char[20 + 1];

	stationName[20] = '\0';//20
	digitType[10] = '\0';  //10
	transferEquipment[12] = '\0';//12
	clockEquipment[12] = '\0'; //12
	seimicMeterName[8] = '\0';//8
	setStationName(singleStation.getStationName().c_str());
	setStationNumber(singleStation.getStationNumber());
	setStationLatitude(singleStation.getStationLatitude());
	setStationElevation(singleStation.getStationElevation());
	setStationLongitude(singleStation.getStationLongitude());
	setDigitType(singleStation.getDigitType().c_str());
	setTransferEquipment(singleStation.getTransferEquipment().c_str());
	setClockEquipment(singleStation.getClockEquipment().c_str());
	setSeimicMeterName(singleStation.getSeimicMeterName().c_str());
	setChannelNumber(singleStation.getChannelNumber());
	setClockDifference(singleStation.getClockDifference());
	setClockType(singleStation.getClockType());
	//strcpy_s(stationName, 20, singleStation.getStationName().c_str());
	setDataUsableFlags(singleStation.getDataUsableFlags());
	setDigitBite(singleStation.getDigitBite());
	setDigitRate(singleStation.getDigitRate());
	setFullVoltage(singleStation.getFullVoltage());
	setAzimuth(singleStation.getAzimuth());
	setIncidence(singleStation.getIncidence());
	setSingleChannels(singleStation.getSingleChannels());
	setBadDataCount(singleStation.getBadDataCount());
}

void SingleStation::operator =(const SingleStation & singleStation) {
	setStationName(singleStation.getStationName().c_str());
	setStationNumber(singleStation.getStationNumber());
	setStationLatitude(singleStation.getStationLatitude());
	setStationElevation(singleStation.getStationElevation());
	setStationLongitude(singleStation.getStationLongitude());
	setDigitType(singleStation.getDigitType().c_str());
	setTransferEquipment(singleStation.getTransferEquipment().c_str());
	setClockEquipment(singleStation.getClockEquipment().c_str());
	setSeimicMeterName(singleStation.getSeimicMeterName().c_str());
	setChannelNumber(singleStation.getChannelNumber());
	setClockDifference(singleStation.getClockDifference());
	setClockType(singleStation.getClockType());
	setDataUsableFlags(singleStation.getDataUsableFlags());
	setDigitBite(singleStation.getDigitBite());
	setDigitRate(singleStation.getDigitRate());
	setFullVoltage(singleStation.getFullVoltage());
	setAzimuth(singleStation.getAzimuth());
	setIncidence(singleStation.getIncidence());
	setSingleChannels(singleStation.getSingleChannels());
	setBadDataCount(singleStation.getBadDataCount());
}

SingleStation::~SingleStation()
{
	if (NULL != stationName) {
		
		delete stationName;//20
	}

	delete digitType;//10
	delete transferEquipment;//12
	delete clockEquipment; //12
	delete seimicMeterName;//8
	
	
}


// function
void SingleStation::read(ifstream & ifs)
{
	char * int32Temp = new char[4 + 1];
	char * floatTemp = new char[4 + 1];
	char * shortTemp = new char[2 + 1];
	int32Temp[4] = '\0';
	floatTemp[4] = '\0';
	shortTemp[2] = '\0';

	ifs.read(int32Temp, 4);
	stationNumber = MathUtils::toInt(int32Temp);

	ifs.read(stationName, 20);

	ifs.read(digitType, 10);

	ifs.read(shortTemp, 2);
	digitBite = MathUtils::toShort(shortTemp);
	
	ifs.read(floatTemp, 4);
	fullVoltage = MathUtils::toFloat(floatTemp);

	ifs.read(int32Temp, 4);
	digitRate = MathUtils::toInt(int32Temp);
	
	ifs.read(int32Temp, 4);
	channelNumber = MathUtils::toInt(int32Temp);

	ifs.read(shortTemp, 2);
	transferType = MathUtils::toShort(shortTemp);

	ifs.read(transferEquipment, 12);

	ifs.read(shortTemp, 2);
	clockType = MathUtils::toShort(shortTemp);

	ifs.read(clockEquipment, 12);

	ifs.read(floatTemp, 4);
	clockDifference = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	stationLatitude = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	stationLongitude = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	stationElevation = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	azimuth = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	incidence = MathUtils::toFloat(floatTemp);

	ifs.read(int32Temp, 4);
	weight = MathUtils::toInt(int32Temp);

	ifs.read(int32Temp, 4);
	velocityModel = MathUtils::toInt(int32Temp);

	ifs.read(int32Temp, 4);
	seimicMeterType = MathUtils::toInt(int32Temp);

	ifs.read(seimicMeterName, 8);
	
	if (digitBite != 16){
		is4Bytes = true;
	}else {
		is4Bytes = false;
	}

	
	for (int i = 0; i < channelNumber; i++)
	{
		string s("xx");
		SingleChannel channel(s);
		channel.read(ifs);
		this->singleChannels.push_back(channel);
	}
	delete int32Temp;
	delete floatTemp;
	delete shortTemp;
}


void SingleStation::readData(ifstream & ifs) {
	char * int32Temp = new char[4];
	ifs.read(int32Temp, 4);
	Int32 flagBits = MathUtils::toInt(int32Temp);
	if (flagBits != 0) {
		//cout << "flagBits: " << flagBits << endl;
		//0������������ 1����������
		badDataCount += 1;
	}
	//{
	//    string msg = string.Format("��ǰ�뵱ǰ̨վ�ı�־λΪ:{1}/{0}", BadDataCounts++, FlagBits);
	//    MessageBox.Show(msg, "��������", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Error, MessageBoxDefaultButton.Button3);
	//}
	dataUsableFlags.push_back(flagBits);
	//for (vector<SingleChannel>::iterator it = singleChannels.begin(); it != singleChannels.end(); it++)
	for(int i = 0; i != channelNumber; i++)
	{
		if (this->singleChannels[i].getContinuePointSec() == 1) {
			//�������ڴ�����
			ifs.seekg((4 * digitRate), ios::cur);
		}
		else {
			this->singleChannels[i].readData(ifs, digitRate, is4Bytes);
			//cout << this->singleChannels[i].getStrForTxt();
			//int step = 4 * digitRate;
			
		}
	}

	delete int32Temp;
}

void SingleStation::clear()
{
	for (int i = 0; i != singleChannels.size(); i++)
	{
		singleChannels[i].clear();
	}
	if (singleChannels.size() >= 1)
	{
		singleChannels.clear();
	}
}

string SingleStation::toString()
{
	string StationInfo;
	if (!singleChannelDisplay)
		StationInfo = toStringByStation();
	else
		StationInfo = toStringBySingleChannel();
	return StationInfo;
}

string SingleStation::toStringBySingleChannel()
{
	stringstream ss;

	ss << "̨վ���     : " << (getStationNumber() + 1) << "\n"   //|   ̨  վ        |  ������  |   4       |                             |  
	   << "̨վ����     : " << getStationName() << "\n"           //|   ̨  ��        |  �ַ���  |   20      |                             |  
	   << "�����ͺ�     : " << getDigitType() << "\n"             //|   �����ͺ�      |  �ַ���  |   10      | ����:EDAS-3                 |  
	   << "�����ֳ�     : " << getDigitBite() << "\n"          //|   �����ֳ�      |  ������  |   2       | ����:16                     |  
	   << "������ѹ     : " << getFullVoltage() << "\n"     //|   ������ѹ      |  ������  |   4       | ����:4.5 ��λΪ��           |  
	   << "������       : " << getDigitRate() << "\n"          //|   ������        |  ������  |   4       | ����:50                     |  
	   << "ͨ������     : " << getChannelNumber() << "\n"   //|   ͨ������      |  ������  |   4       | ����:3                      |  
	   << "���ݴ��䷽ʽ : " << getTransferType() << "\n"       //|   ���ݴ��䷽ʽ  |  ������  |   2       | ע1:                        |  
	   << "�����豸�ͺ� : " << getTransferEquipment() << "\n"            //|   �����豸�ͺ�  |  �ַ���  |   12      | ����:                       |  
	   << "��ʱ��ʽ     : " << getClockType() << "\n"       //|   ��ʱ��ʽ      |  ������  |   2       | ע2:                        |  
	   << "ʱ���ͺ�     : " << getClockEquipment() << "\n"            //|   ʱ���ͺ�      |  ������  |   12      |  ����:GPS-121               |  
	   << "�Ӳ�         : " << getClockDifference() << "\n" //|   �Ӳ�          |  ������  |   4       | ����:0.0                    |  
	   << "γ��         : " << getStationLatitude() << "\n"        //|   γ��          |  ������  |   4       | ����������                  |  
	   << "����         : " << getStationLongitude() << "\n"       //|   ����          |  ������  |   4       | ����������                  |  
	   << "�߳�         : " << getStationElevation() << "\n"       //|   �߳�          |  ������  |   4       | ����������                  |  
	   << "��λ��       : " << getAzimuth() << "\n"         //|   ��λ��        |  ������  |   4       | ���ھ�����������ת���������|  
	   << "�����       : " << getIncidence() << "\n"       //|   �����        |  ������  |   4       | ���ھ�����������ת���������|  
	   << "Ȩ��         : " << getWeight() << "\n"          //|   Ȩ��          |  ������  |   4       | 0: ��, 1: ��                |  ? 2
	   << "�ٶ�ģ��     : " << getVelocityModel() << "\n"   //|   �ٶ�ģ��      |  ������  |   4       | ע3:                        |  ? 2
	   << "ԭʼ�������� : " << getSeimicMeterType() << "\n" //|   ԭʼ��������  |    ����  |   4       | ע4:                        |  
	   << "������ͺ�   : " << getSeimicMeterName() << "\n";            //|   ������ͺ�    |   �ַ��� |   8       | ����:FBS-3                  | ? 12 

	
	for (int i = 0; i != singleChannels.size(); i++ )//stationNumber; i++)
	{
		ss << singleChannels[i].toString();   // ��̨վ����ͨ����������  //????????
	}
	return ss.str();
}

string  SingleStation::toStringByStation()
{
	stringstream ss;
	ss << "̨վ���     : " << (getStationNumber() + 1) << "\n"  //|   ̨  վ        |  ������  |   4       |                             |  
		 << "̨վ����     : " << getStationName() << "\n"        //|   ̨  ��        |  �ַ���  |   20      |                             |  
		 << "�����ͺ�     : " << getDigitType() << "\n"   //|   �����ͺ�      |  �ַ���  |   10      | ����:EDAS-3                 |  
		 << "�����ֳ�     : " << getDigitBite() << "\n"     //|   �����ֳ�      |  ������  |   2       | ����:16                     |  
		 << "������ѹ     : " << getFullVoltage() << "\n"      //|   ������ѹ      |  ������  |   4       | ����:4.5 ��λΪ��           |  
		 << "������       : " << getDigitRate() << "\n"      //|   ������        |  ������  |   4       | ����:50                     |  
		 << "ͨ������     : " << getChannelNumber() << "\n"        //|   ͨ������      |  ������  |   4       | ����:3                      |  
		 << "���ݴ��䷽ʽ : " << getTransferType() << "\n"        //|   ���ݴ��䷽ʽ  |  ������  |   2       | ע1:                        |  
		 << "�����豸�ͺ� : " << getTransferEquipment() << "\n"            //|   �����豸�ͺ�  |  �ַ���  |   12      | ����:                       |  
		 << "��ʱ��ʽ     : " << getClockType() << "\n"   //|   ��ʱ��ʽ      |  ������  |   2       | ע2:                        |  
		 << "ʱ���ͺ�     : " << getClockEquipment() << "\n"           //|   ʱ���ͺ�      |  ������  |   12      |  ����:GPS-121               |  
		 << "�Ӳ�         : " << getClockDifference() << "\n"  //|   �Ӳ�          |  ������  |   4       | ����:0.0                    |  
		 << "γ��         : " << getStationLatitude() << "\n"         //|   γ��          |  ������  |   4       | ����������                  |  
		 << "����         : " << getStationLongitude() << "\n"       //|   ����          |  ������  |   4       | ����������                  |  
		 << "�߳�         : " << getStationElevation() << "\n"        //|   �߳�          |  ������  |   4       | ����������                  |  
		 << "��λ��       : " << getAzimuth() << "\n"         //|   ��λ��        |  ������  |   4       | ���ھ�����������ת���������|  
		 << "�����       : " << getIncidence() << "\n"         //|   �����        |  ������  |   4       | ���ھ�����������ת���������|  
		 << "Ȩ��         : " << getWeight() << "\n"       //|   Ȩ��          |  ������  |   4       | 0: ��, 1: ��                |  ? 2
		 << "�ٶ�ģ��     : " << getVelocityModel() << "\n"     //|   �ٶ�ģ��      |  ������  |   4       | ע3:                        |  ? 2
		 << "ԭʼ�������� : " << getSeimicMeterType() << "\n"  //|   ԭʼ��������  |    ����  |   4       | ע4:                        |  
		 << "������ͺ�   : " << getSeimicMeterName() << "\n";  //|   ������ͺ�    |   �ַ��� |   8       | ����:FBS-3                  | ? 12 
	ss << toStringAllChangesData();  // ??????
	//cout << ss.str();
	string str = ss.str();
	return str;
}



string SingleStation::toStringOneChannel(int & channelIndex){
	stringstream ss;
	if (channelIndex < 0) 
		channelIndex = 0;
	if (channelIndex >= channelNumber) 
		channelIndex = channelNumber - 1;
	ss << singleChannels[channelIndex].toString();
	return ss.str();
}


string SingleStation::toStringAllChangesData(){
	stringstream ss;
	ss << "";
	ss << "��ǰ��ѡ��̨վ����ͨ���Ĳ������� : \n\n";
	ss << " ͨ������ : \t\t";

	for (int i = 0; i < channelNumber; i++) //i < channelNumber; i++)
	{
		//cout << singleChannels.size() << endl;
		ss << singleChannels[i].getChannelName() << "\t\t\t";                 //|   ͨ������   |  �ַ���  |   12   |       |  
	}
	ss << "\n ͨ����� : \t\t";
	for (int i = 0; i < channelNumber; i++)
	{
		ss << (singleChannels[i].getChannelNumber() + 1) << "\t\t\t";  //|   ͨ�����   |  ����    |   4    |       |  
	}
	ss << "\n �������� : \t";
	for (int i = 0; i < channelNumber; i++)
	{
		ss << singleChannels[i].getGain() << ",  ";             //|   ��������   |  ����    |   4    |      |  
	}
	ss << "\n ��Ӧ���� : \t\t";
	for (int i = 0; i < channelNumber; i++)
	{
		ss << singleChannels[i].getResponseOrder() << "\t\t\t";    //|  ��Ӧ����  |  ����   |   4   |     |  
	}
	ss << "\n ��Ӧ���� : \t\t";
	for (int i = 0; i < channelNumber; i++)
	{
		ss << singleChannels[i].getResponseType() << "\t\t\t";     //|  ��Ӧ����  |  ����   |   4   |     |  
	}
	ss << "\n Ƶ����Ŀ : \t\t";
	for (int i = 0; i < channelNumber; i++)
	{
		ss << singleChannels[i].getFrequenceNumber() << "\t\t\t";   //|   Ƶ����Ŀ      |  ����    |   4   |     |  
	}
	ss << "\n";
	ss << "\n���������\t����ֵ\t����ֵ\t����ֵ\n";
	SingleChannel sc1 = singleChannels[0];
	int waveLength = singleChannels[0]
		.getWaveData().size();
	
	
	for (int i = 0; i < channelNumber; i++)
	{
		if (waveLength < singleChannels[i].getWaveData().size()) 
			waveLength = singleChannels[i].getWaveData().size();
	}
	for (int j = 0; j < waveLength; j++)
	{
		ss << "\t" << (j + 1) << "\t\t";
		for (int i = 0; i < channelNumber; i++)
		{
			SingleChannel sc = singleChannels[i];
			
			ss << sc.getWaveData()[j] <<  "\t\t\t";                 // ��ͨ����������
			
		}
		ss << "\n";
	}
	ss << "\n";
	
	return ss.str();
}




// Get and Set function
// Set function
void SingleStation::setStationNumber(const Int32 & value) {
	stationNumber = value;
}

//char[20];
void SingleStation::setStationName(const char * value) {
	int len = strlen(value);
	len = (20 < len) ? 20 : len;
	stationName[len] = '\0';
	for (int i = 0; i < len; i++) {
		stationName[i] = value[i];
	}
} 

//char[10];
void SingleStation::setDigitType(const char* value) {
	int len = strlen(value);
	len = (10 < len) ? 10 : len;
	digitType[len] = '\0';
	for (int i = 0; i < len; i++) {
		digitType[i] = value[i];
	}
}

void SingleStation::setDigitBite(const short& value) {
	digitBite = value;
}

void SingleStation::setFullVoltage(const float & value) {
	fullVoltage = value;
}

void SingleStation::setDigitRate(const Int32 & value) {
	digitRate = value;
}

void SingleStation::setChannelNumber(const Int32 & value) {
	channelNumber = value;
}

void SingleStation::setTransferType(const short & value) {
	transferType = value;
}

//char[12];
void SingleStation::setTransferEquipment(const char * value) {
	int len = strlen(value);
	len = (12 < len) ? 12 : len;
	transferEquipment[len] = '\0';
	for (int i = 0; i < len; i++) {
		transferEquipment[i] = value[i];
	}
}

void SingleStation::setClockType(const short & value) {
	clockType = value;
}

//char[12];
void SingleStation::setClockEquipment(const char * value) {
	int len = strlen(value);
	len = (12 < len) ? 12 : len;
	clockEquipment[len] = '\0';
	for (int i = 0; i < len; i++) {
		clockEquipment[i] = value[i];
	}
}

void SingleStation::setClockDifference(const float & value) {
	clockDifference = value;
}

void SingleStation::setStationLatitude(const float & value) {
	stationLatitude = value;
}

void SingleStation::setStationLongitude(const float & value) {
	stationLongitude = value;
}

void SingleStation::setStationElevation(const float & value) {
	stationElevation = value;
}

void SingleStation::setAzimuth(const float & value) {
	azimuth = value;
}

void SingleStation::setIncidence(const float & value) {
	incidence = value;
}

void SingleStation::setWeight(const Int32 & value) {
	weight = value;
}

void SingleStation::setVelocityModel(const Int32 & value) {
	velocityModel = value;
}

void SingleStation::setSeimicMeterType(const Int32 & value) {
	seimicMeterType = value;
}

//char[8]
void SingleStation::setSeimicMeterName(const char * value) {
	int len = strlen(value);
	len = (8 < len) ? 8 : len;
	seimicMeterName[len] = '\0';
	for (int i = 0; i < len; i++) {
		seimicMeterName[i] = value[i];
	}
}

//default true;
void SingleStation::SetIs4Bytes(const bool & value) {
	is4Bytes = value;
}

//default false;
void SingleStation::setSingleChannelDisplay(const bool & value) {
	singleChannelDisplay = value;
}

void SingleStation::setSingleChannels(const vector<SingleChannel> & value) {
	singleChannels.assign(value.begin(), value.end());
}

void SingleStation::setDataUsableFlags(const vector<Int32> & value) {
	dataUsableFlags.assign(value.begin(), value.end());
}

void SingleStation::setBadDataCount(const int & value) {
	badDataCount = value;
}

 //Get Function
Int32 SingleStation::getStationNumber()const {
	return stationNumber;
}

//char[20];
string SingleStation::getStationName() const {
	return string(stationName);
}

//char[10];
string SingleStation::getDigitType()const {
	return string(digitType);
}

short SingleStation::getDigitBite()const {
	return digitBite;
}

float SingleStation::getFullVoltage()const {
	return fullVoltage;
}

Int32 SingleStation::getDigitRate()const {
	return digitRate;
}

Int32 SingleStation::getChannelNumber() const {
	return channelNumber;
}

short SingleStation::getTransferType()const {
	return transferType;
}

//char[12];
string SingleStation::getTransferEquipment()const {
	return string(transferEquipment);
}

short SingleStation::getClockType()const {
	return clockType;
}

//char[12];
string SingleStation::getClockEquipment() const {
	return string(clockEquipment);
}

float SingleStation::getClockDifference()const {
	return clockDifference;
}

float SingleStation::getStationLatitude()const {
	return stationLatitude;
}

int SingleStation::getBadDataCount()const {
	return badDataCount;
}

float SingleStation::getStationLongitude()const {
	return this->stationLongitude;
}

float SingleStation::getStationElevation()const {
	return this->stationElevation;
}

float SingleStation::getAzimuth()const {
	return azimuth;
}

float SingleStation::getIncidence()const {
	return incidence;
}

Int32 SingleStation::getWeight()const {
	return weight;
}

Int32 SingleStation::getVelocityModel()const {
	return velocityModel;
}

Int32 SingleStation::getSeimicMeterType()const {
	return seimicMeterType;
}

//char[8]
string SingleStation::getSeimicMeterName()const {
	return string(seimicMeterName);
}

//default  true;
bool SingleStation::getIs4Bytes()const {
	return is4Bytes;
}

//default   false;
bool SingleStation::getSingleChannelDisplay()const {
	return singleChannelDisplay;
}

vector<SingleChannel> SingleStation::getSingleChannels()const {
	return singleChannels;
}
vector<Int32> SingleStation::getDataUsableFlags()const {
	return dataUsableFlags;
}
//Get and Set function end


