#pragma once
#include "stdafx.h"
#include "EvtFileHeader.h"


//public 
EvtFileHeader::EvtFileHeader() {
	this->eventFileName = "no content!";
	eventFileFlag[16] = '\0';
	recordMashineType[16] = '\0';
	netWideName[80] = '\0';
	epicentreName[12] = '\0';
	operatorName[12] = '\0';
	reserved[44] = '\0';
	//Read();
}

EvtFileHeader::EvtFileHeader(string & fileName)
{
	eventFileFlag[16] = '\0';
	recordMashineType[16] = '\0';
	netWideName[80] = '\0';
	epicentreName[12] = '\0';
	operatorName[12] = '\0';
	reserved[44] = '\0';
	this->eventFileName = fileName;
	read();
}

EvtFileHeader::~EvtFileHeader() {
	delete eventFileFlag;
	delete recordMashineType;
	delete netWideName;
	delete epicentreName;
	delete operatorName;
	delete reserved;
}

//set and get function
//get function


string EvtFileHeader::getRecordMashineType() {
	return this->recordMashineType;
}

Int32 EvtFileHeader::getRecordFileType() {
	return this->recordFileType;
}

int EvtFileHeader::getDealHistory() {
	return this->dealHistory;
}

string EvtFileHeader::getNetWideName() {
	return this->netWideName;
}

Int32 EvtFileHeader::getNumberStation() {
	return this->numberStation;
}

float EvtFileHeader::getCentreLatitude() {
	return this->centreLatitude;
}

float EvtFileHeader::getCentreLongitude() {
	return this->centreLongitude;
}

float EvtFileHeader::getCentreElevation() {
	return this->centreElevation;
}

double EvtFileHeader::getOrigintime() {
	return this->origintime;
}

float EvtFileHeader::getEpicentrelatitude() {
	return this->epicentreLatitude;
}

float EvtFileHeader::getEpicentreLongitude() {
	return this->epicentreLongitude;
}

float EvtFileHeader::getHypocentreDepth() {
	return this->hypocentreDepth;
}

float EvtFileHeader::getMagnitudeMl() {
	return this->magnitudeMl;
}

float EvtFileHeader::getMagnitudeMd() {
	return this->magnitudeMd;
}

float EvtFileHeader::getMagnitudeMs() {
	return this->magnitudeMs;
}

float EvtFileHeader::getMagnitudeMb() {
	return this->magnitudeMb;
}

string EvtFileHeader::getEpicentreName() {
	return this->epicentreName;
}

string EvtFileHeader::getOperatorName() {
	return this->operatorName;
}

Int32 EvtFileHeader::getOperatorNumber() {
	return this->operatorNumber;
}

Int32 EvtFileHeader::getDealSecond() {
	return this->dealSecond;
}

double EvtFileHeader::getDealTime() {
	return this->dealTime;
}

string EvtFileHeader::getReserved() {
	return this->reserved;
}

Int32 EvtFileHeader::getDaytime() {
	return this->daytime;
}

short EvtFileHeader::getYear() {
	return this->year;
}

short EvtFileHeader::getMonth() {
	return this->month;
}

short EvtFileHeader::getDay() {
	return this->day;
}

short EvtFileHeader::getHour() {
	return this->hour;
}

short EvtFileHeader::getMinute() {
	return this->minute;
}

short EvtFileHeader::getSecond() {
	return this->second;
}

Int32 EvtFileHeader::getRecordLength() {
	return this->recordLength;
}

string EvtFileHeader::getEventFileName() {
	return eventFileName;
}

string EvtFileHeader::getEventFileFlag() {
	return eventFileFlag;
}

//set function
void EvtFileHeader::setEventFile(string value) {
	int Len = value.size();
	const char* str = value.c_str();
	Len = (16 < Len) ? 16 : Len;
	for (int i = 0; i < Len; i++)
		eventFileFlag[i] = str[i];
}

void EvtFileHeader::setRecordMashineType(string value) {
	int len = value.size();
	const char* str = value.c_str();
	len = (16 < len) ? 16 : len;
	for (int i = 0; i < len; i++)
		this->recordMashineType[i] = str[i];
}  

void EvtFileHeader::setRecordFileType(Int32 value) {
	this->recordFileType = value;
}

void EvtFileHeader::setDealHistory(Int32 value) {
	this->dealHistory = value;
}

void EvtFileHeader::setNetWideName(string value) {
	int len = value.size();
	const char* str = value.c_str();
	len = (16 < len) ? 16 : len;
	for (int i = 0; i < len; i++)
		this->netWideName[i] = str[i];
}

void EvtFileHeader::setNumberStation(Int32 value) {
	this->numberStation = value;
}

void EvtFileHeader::setCentreLatitude(float value) {
	this->centreLatitude = value;
}

void EvtFileHeader::setCentreLongitude(float value) {
	this->centreLongitude;
}

//����
void EvtFileHeader::setCentreElevation(float value) {
	this->centreElevation = value;
}

void EvtFileHeader::setOrigintime(double value) {
	this->origintime = value;
}

void EvtFileHeader::setEpicentreLatitude(float value) {
	this->epicentreLatitude = value;
}

void EvtFileHeader::setEpicentreLongitude(float value) {
	this->epicentreLongitude;
}

void EvtFileHeader::setHypocentreDepth(float value) {
	this->hypocentreDepth;
}

void EvtFileHeader::setMagnitudeMl(float value) {
	this->magnitudeMl;
}

void EvtFileHeader::setMagnitudeMd(float value) {
	this->magnitudeMd;
}

void EvtFileHeader::setMagnitudeMs(float value) {
	this->magnitudeMs;
}

void EvtFileHeader::setMagnitudeMb(float value) {
	this->magnitudeMb;
}

void EvtFileHeader::setEpicentreName(float value) {
	this->epicentreName;
}

void EvtFileHeader::setOperatorName(float value) {
	this->operatorName;
}

void EvtFileHeader::setOperatorNumber(Int32 value) {
	this->operatorNumber;
}

void EvtFileHeader::setDealSecond(Int32 value) {
	this->dealSecond;
}

void EvtFileHeader::setDealTime(double value) {
	this->dealTime;
}

void EvtFileHeader::setReserved(string  value) {
	this->reserved;
}

void EvtFileHeader::setDaytime(Int32 value) {
	this->daytime = value;
}

void EvtFileHeader::setYear(short value) {
	this->year = value;
}

void EvtFileHeader::setMonth(short value) {
	this->month = value;
}

void EvtFileHeader::setDay(short value) {
	this->day = value;
}

void EvtFileHeader::setHour(short value) {
	this->hour = value;
}

void EvtFileHeader::setMinute(short value) {
	this->minute;
}

void EvtFileHeader::setSecond(short value) {
	this->second = value;
}

void EvtFileHeader::setRecordLength(Int32 value) {
	this->recordLength = value;
}

void EvtFileHeader::setEventFileName(string & value) {
	eventFileName = value;
}

//set function end
//set and get function end


void EvtFileHeader::read()
{
	//����ļ������ڣ�����void�����������д���
	if (!fstream(this->eventFileName))  //	 evtFileName))//File.Exists(EvtFileName))
	{
		string ErrorMessage = "�ļ�������!";
		//throw ErrorMessage; //�׳��쳣
		// System.Windows.Forms.MessageBoxButtons(ErrorMessage);
		return;
	}

	//FileStream fstream = new FileStream(EvtFileName, FileMode.Open, FileAccess.Read);
	//fstream.Seek(0, SeekOrigin.Begin);
	//BinaryReader binReader = new BinaryReader(fstream, System.Text.Encoding.ASCII);
	//eventfile = binReader.ReadChars(16);
	/*
	string message;
	if (EvenFileFlag.Equals("digital event"))
	{
	message = string.Format("���ļ�\"%s\"ʱ����    \n\n�����Ŀǰ�в���ʶ�������ļ��ĸ�ʽ��  \n�볢��ѡ�����������ļ���  ", EvtFileName);
	MessageBox.Show(message);
	binReader.Close();
	fstream.Close();
	return;
	}
	*/

	//�Զ����ƴ��ļ�
	ifstream ifs(this->eventFileName, ios::in | ios::binary, 0);//0ֻ����ʽ�򿪣�2�����ļ���4ϵͳ�ļ�
	ifs.seekg(0, ios::beg);
	char * temp = new char[16];
	ifs.read(temp, 16); //��ȡ16���ַ�
	this->eventFileName = string(temp);

	string message;

	//����ַ������,�������ʶ����ļ�
	if (string(eventFileFlag).compare("digital event") == 0)
	{
		message = string("���ļ�");//\"%s\//
		message.append(this->eventFileName);
		message.append("ʱ����    \n\n�����Ŀǰ�в���ʶ�������ļ��ĸ�ʽ��  \n�볢��ѡ�����������ļ���  ");

		//message = string.Format("���ļ�\"%s\"ʱ����    \n\n�����Ŀǰ�в���ʶ�������ļ��ĸ�ʽ��  \n�볢��ѡ�����������ļ���  ", EvtFileName);
		//MessageBox.Show(message);
		//binReader.Close();
		ifs.close(); //fstream.Close();
		return;
	}

	memset(temp, NULL, 16);
	ifs.read(eventFileFlag, 16); //binReader.ReadChars(16));
	memset(temp, NULL, 16);

	//recordMashineType = string(binReader.ReadChars(16));
	//RecordFileType = binReader.ReadInt32();
	//DealingHistory = binReader.ReadInt32();
	//netWideName = new string(binReader.ReadChars(80));
	//NumberStation = binReader.ReadInt32();
	//CentreLatitude = binReader.ReadSingle();
	//CentreLongitude = binReader.ReadSingle();
	//CentreElevation = binReader.ReadSingle();
	//OriginTime = binReader.ReadDouble();
	//EpicentreLatitude = binReader.ReadSingle();
	//epicname = binReader.ReadBytes(12);
	//op_name = binReader.ReadBytes(12);
	//EpicentreName = new string(binReader.ReadChars(12));
	//OperatorName = new string(binReader.ReadChars(12));
	//OperatorNumber = binReader.ReadInt32();
	//DealingSeconds = binReader.ReadInt32();
	//DealingTime = binReader.ReadDouble();
	//Reserved = new string(binReader.ReadChars(44));
	//DayTime = binReader.ReadInt32();
	//Year = binReader.ReadInt16();
	//Month = binReader.ReadInt16();
	//Day = binReader.ReadInt16();
	//Hour = binReader.ReadInt16();
	//Minute = binReader.ReadInt16();
	//Second = binReader.ReadInt16();
	//RecordLength = binReader.ReadInt32();


	ifs.read(this->recordMashineType, 16);
	
	char* int32Temp = new char[4];
	ifs.read(int32Temp, 4);
	this->recordFileType = atoi(int32Temp);
	memset(int32Temp, NULL, 4);
	delete temp; // �ͷ�ǰ���new temp[16]

	ifs.read(this->netWideName, 80);
	ifs.read(int32Temp, 4);
	numberStation = atoi(int32Temp);

	char *floatTemp = new char[sizeof(float)];
	ifs.read(floatTemp, sizeof(float));
	centreLatitude = (float)atof(int32Temp);

	ifs.read(floatTemp, sizeof(float));
	centreLatitude = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	centreLongitude = (float)atof(floatTemp);
	
	ifs.read(floatTemp, sizeof(float));
	centreElevation = (float)atof(floatTemp);
	
	char * doubleTemp = new char[sizeof(double)];

	ifs.read(doubleTemp, sizeof(double));
	this->origintime = (float)atof(doubleTemp);
	
	ifs.read(floatTemp, sizeof(float));
	epicentreLatitude = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	hypocentreDepth = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMl = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMd = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMs = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMb = (float)atof(floatTemp);

	ifs.read(this->epicentreName, 12);
	ifs.read(this->operatorName, 12);
	
	
	ifs.read(int32Temp, sizeof(Int32));
	this->operatorNumber = atoi(int32Temp);
	
	ifs.read(int32Temp, sizeof(Int32));
	this->dealSecond = atoi(int32Temp);


	

	ifs.read(doubleTemp, sizeof(double));
	dealTime = atof(doubleTemp);

	ifs.read(reserved, 44);

	ifs.read(int32Temp, sizeof(Int32));
	daytime = atoi(int32Temp);

	char* int16temp = new char[sizeof(short)];
	ifs.read(int16temp, sizeof(short));
	year = (short)atoi(int16temp);

	ifs.read(int16temp, sizeof(short));
	month = atoi(int16temp);

	ifs.read(int16temp, sizeof(short));
	day = (short)atoi(int16temp);

	ifs.read(int16temp, sizeof(short));
	hour = atoi(int16temp);

	ifs.read(int16temp, sizeof(short));
	minute = (short)atoi(int16temp);

	ifs.read(int16temp, sizeof(short));
	second = (short)atoi(int16temp);


	ifs.read(int32Temp, sizeof(Int32));
	recordLength = atoi(int32Temp);
	
	delete int32Temp;
	delete floatTemp;
	delete doubleTemp;

	ifs.close(); // �ر��ļ�
	
}


/*
void EvtFileHeader::readHeader(ifstream & ifs) {
	ifs.seekg(0, ios::beg);
	ifs.read(eventFile, 16); //��ȡ16���ַ�
	//this->eventFileName = string(temp);
	//cout << eventFile << endl;
	//����ַ������,�������ʶ����ļ�
	if (this->eventFileFlag.compare("digital event") == 0)
	{
		string message("���ļ�");  //\"%s\//
		message.append(this->eventFileName);
		message.append("ʱ����    \n\n�����Ŀǰ�в���ʶ�������ļ��ĸ�ʽ��  \n�볢��ѡ�����������ļ���  ");

		//message = string.Format("���ļ�\"%s\"ʱ����    \n\n�����Ŀǰ�в���ʶ�������ļ��ĸ�ʽ��  \n�볢��ѡ�����������ļ���  ", EvtFileName);
		//MessageBox.Show(message);
		//binReader.Close();
		ifs.close(); //fstream.Close();
		return;
	}

	//memset(temp, NULL, 16);
	char * temp = new char[16];
	char* int32Temp = new char[4];
	char *floatTemp = new char[sizeof(float)];
	char* shortTemp = new char[sizeof(short)];
	char * doubleTemp = new char[8];


	ifs.read(temp, 16);
	this->eventFileFlag = string(temp); //binReader.ReadChars(16));
	memset(temp, NULL, 16);

	ifs.read(this->recordMashineType, 16);

	ifs.read(int32Temp, 4);
	this->recordFileType = atoi(int32Temp);
	memset(int32Temp, NULL, 4);
	
	ifs.read(int32Temp, 4);
	dealHistory = (Int32)atoi(int32Temp);

	ifs.read(this->netWideName, 80);

	ifs.read(int32Temp, 4);
	numberStation = atoi(int32Temp);

	ifs.read(floatTemp, 4);
	centreLatitude = (float)atof(floatTemp);

	ifs.read(floatTemp, 4);
	centreLongitude = (float)atof(floatTemp);

	ifs.read(floatTemp, 4);
	centreElevation = (float)atof(floatTemp);

	ifs.read(doubleTemp, sizeof(double));
	this->origintime = (double)atof(doubleTemp);

	ifs.read(floatTemp, sizeof(float));
	epicentreLatitude = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	epicentreLongitude = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	hypocentreDepth = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMl = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMd = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMs = (float)atof(floatTemp);

	ifs.read(floatTemp, sizeof(float));
	magnitudeMb = (float)atof(floatTemp);

	ifs.read(this->epicentreName, 12);
	ifs.read(this->operatorName, 12);

	ifs.read(int32Temp, 4);
	this->operatorNumber = atoi(int32Temp);

	ifs.read(int32Temp, 4);
	this->dealSecond = atoi(int32Temp);

	ifs.read(doubleTemp, sizeof(double));
	dealTime = atof(doubleTemp);

	ifs.read(reserved, 44);

	ifs.read(int32Temp, 4);
	daytime = (Int32)atoi(int32Temp);

	ifs.read(shortTemp, 2);
	year = (short)atoi(shortTemp);

	ifs.read(shortTemp, 2);
	month = (short)atoi(shortTemp);

	ifs.read(shortTemp, 2);
	day = (short)atoi(shortTemp);

	ifs.read(shortTemp, 2);
	hour = (short)atoi(shortTemp);

	ifs.read(shortTemp, 2);
	minute = (short)atoi(shortTemp);

	ifs.read(shortTemp, 2);
	second = (short)atoi(shortTemp);

	ifs.read(int32Temp, 4);
	recordLength = atoi(int32Temp);

	delete temp;
	delete int32Temp;
	delete floatTemp;
	delete doubleTemp;

	ifs.close(); // �ر��ļ�

}
*/

void EvtFileHeader::readHeader(ifstream & ifs) {
	//ifs.clear();
	ifs.seekg(0, ios::beg);
	ifs.read(eventFileFlag, 16); //��ȡ16���ַ�
	//����ַ������,�������ʶ����ļ�
	if (string(eventFileFlag).compare("digital event") != 0)
	{
		string message("���ļ�");  //\"%s\//
		message.append(this->eventFileName);
		message.append("ʱ����    \n\n�����Ŀǰ�в���ʶ�������ļ��ĸ�ʽ��  \n�볢��ѡ�����������ļ���  ");

		//message = string.Format("���ļ�\"%s\"ʱ����    \n\n�����Ŀǰ�в���ʶ�������ļ��ĸ�ʽ��  \n�볢��ѡ�����������ļ���  ", EvtFileName);
		//MessageBox.Show(message);
		//binReader.Close();
		//ifs.close(); //fstream.Close();
		return;
	}

	
	//memset(temp, NULL, 16);
	
	char * temp = new char[16 + 1];
	char * int32Temp = new char[4 + 1];
	char * floatTemp = new char[4 + 1];
	char * shortTemp = new char[2 + 1];
	char * doubleTemp = new char[8 + 1];
	
	temp[16] = '\0';
	int32Temp[4] = '\0';
	floatTemp[4] = '\0';
	shortTemp[2] = '\0';
	doubleTemp[8] = '\0';
	//ifs.read(eventFileFlag, 16); //��ȡ16���ַ�
	ifs.read(recordMashineType, 16);

	ifs.read(int32Temp, 4);
	recordFileType = MathUtils::toInt(int32Temp);

	ifs.read(int32Temp, 4);
	dealHistory = MathUtils::toInt(int32Temp);
	
	ifs.read(this->netWideName, 80);

	ifs.read(int32Temp, 4);
	numberStation = MathUtils::toInt(int32Temp);

	
	ifs.read(floatTemp, 4);
	centreLatitude = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	centreLongitude = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	centreElevation = MathUtils::toFloat(floatTemp);
	
	memset(doubleTemp, 0, 8);
	ifs.seekg(0, ios::cur);
	ifs.read(doubleTemp, 8); 
	origintime = MathUtils::toDouble(doubleTemp);
	
	memset(floatTemp, 0, 4);
	ifs.read(floatTemp, 4);
	epicentreLatitude = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	epicentreLatitude = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	hypocentreDepth = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	magnitudeMl = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	magnitudeMd = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	magnitudeMs = MathUtils::toFloat(floatTemp);

	ifs.read(floatTemp, 4);
	magnitudeMb = MathUtils::toFloat(floatTemp);

	ifs.read(this->epicentreName, 12);
	ifs.read(this->operatorName, 12);

	ifs.read(int32Temp, 4);
	operatorNumber = MathUtils::toInt(int32Temp);

	ifs.read(int32Temp, 4); 
	dealSecond = MathUtils::toInt(int32Temp);

	ifs.read(doubleTemp, 8);
	dealTime = MathUtils::toDouble(doubleTemp);

	ifs.read(reserved, 44);

	ifs.read(int32Temp, 4);
	daytime = MathUtils::toInt(int32Temp);

	ifs.read(shortTemp, 2);
	year = MathUtils::toShort(shortTemp);

	ifs.read(shortTemp, 2);
	month = MathUtils::toShort(shortTemp);

	ifs.read(shortTemp, 2);
	day = MathUtils::toShort(shortTemp);

	ifs.read(shortTemp, 2);
	hour = MathUtils::toShort(shortTemp);

	ifs.read(shortTemp, 2);
	minute = MathUtils::toShort(shortTemp);

	ifs.read(shortTemp, 2);
	second = MathUtils::toShort(shortTemp);

	ifs.read(int32Temp, 4);
	recordLength = MathUtils::toInt(int32Temp);

	delete temp;
	delete int32Temp;
	delete floatTemp;
	delete doubleTemp;

}


string EvtFileHeader::toString() {
	/*
	% ��¼��  ��������ϵͳ����������ļ�˵��
	% ����һ���¼������ļ��ṹ
	% ����1.1   �¼������ļ�����ṹʾ��
	%   ����ͼ��ʾ�� �¼��ļ�������������ɣ����Ƿֱ����¼�ͷ��̨վ�����Ͳ������ݣ�
	%   ������־���ṹ��������й�ͼ��
	%                     ��������������������������������������
	%                     ��     �� �� ͷ                     ��
	%                     �ǩ�����������������������������������
	%                     ��     ��һ��̨վ����            �� ��
	%                     �ĩ�����������������������������������
	%                     ��     ��һͨ������              �� ��
	%                     ��     [�ڶ�ͨ������                ��
	%                     ��        : ]                       ��
	%                     �ĩ�����������������������������������
	%                     ��     �ڶ���̨վ����            �� ��
	%                     �ĩ�����������������������������������
	%                     ��     ��һͨ������            ��   ��
	%                     ��     [�ڶ�ͨ������                ��
	%                     ��        : ]                       ��
	%                     �ĩ�����������������������������������
	%                     ��         :                        ��
	%                     �ĩ�����������������������������������
	%                     ��     ��N��̨վ����           ��   ��
	%                     �ĩ�����������������������������������
	%                     ��     ��һͨ������            ��   ��
	%                     ��     [�ڶ�ͨ������                ��
	%                     ��        : ]                       ��
	%                     �ǩ�����������������������������������
	%                     ��     ��һ��̨վ����           ��  �� ��һ�� ��ʼ��
	%                     �ĩ�����������������������������������
	%                     ��     [�ڶ���̨վ����          ��  ��
	%                     �ĩ�����������������������������������
	%                     ��          :                    �� ��
	%                     �ĩ�����������������������������������
	%                     ��     ��N��̨վ����]            �� ����һ�� ������
	%                     �ĩ�����������������������������������
	%                     ��     {��һ��̨վ����            ���� �ڶ��� ��ʼ��
	%                     �ĩ�����������������������������������
	%                     ��     [�ڶ���̨վ����          ��  ��
	%                     �ĩ�����������������������������������
	%                     ��          :                  ��   ��
	%                     �ĩ�����������������������������������
	%                     ��     ��N��̨վ����]            �� ���ڶ��� ������
	%                     �ĩ�����������������������������������
	%                     ��          :                    �� ��
	%                     ��          :                    �� ��
	%                     �ĩ�����������������������������������
	%                     ��     ��һ��̨վ����             ���� ���һ�� ��ʼ��
	%                     �ĩ�����������������������������������
	%                     ��     [�ڶ���̨վ����           �� ��
	%                     �ĩ�����������������������������������
	%                     ��          :                    �� ��
	%                     �ĩ�����������������������������������
	%                     ��     ��N��̨վ����]}            ���������һ�� ������
	%                     ��������������������������������������



	% ����1.2   �¼���¼ͷ���ݽṹ (���ֳ� 276 =  16+16+4+4+96+48+72+4+12+4)
	% +----------------------------------------------------------------------+
	% |   �� Ŀ �� ��    |  �� ��  |  �� ��    |     ��      ע              |
	% +----------------------------------------------------------------------+
	% |  �¼��ļ���־    |  �ַ��� |   16      | ��Ϊdigital event    ע0��  |
	% +----------------------------------------------------------------------+
	% |  ��¼��������    |  �ַ��� |   16      | PC �� Work Station          |
	% +----------------------------------------------------------------------+
	% |  �ļ���¼����    |  ����   |    4      | ע1��                       |
	% +----------------------------------------------------------------------+
	% |  ������        |  ����   |    4      | ע2��                       |
	% +----------------------------------------------------------------------+
	% |  ̨������        |  �ṹ   |    96     | �����̨������˵��          |
	% +----------------------------------------------------------------------+
	% |  �������        |  �ṹ   |    48     | �����                      |
	% +----------------------------------------------------------------------+
	% |  ����������Ϣ    |  �ṹ   |    72     | �����                      |
	% +----------------------------------------------------------------------+
	% |  ���ݿ�ʼʱ��    |  ������ |    4     | ��1970-1-1 00:00:00���������|
	% +----------------------------------------------------------------------+
	% |  ���ݿ�ʼʱ��    |  �ṹ   |     12    | �����������������ꡢ�¡��ա�|
	% |                  |         |           |                ʱ���֡���   |
	% +----------------------------------------------------------------------+
	% |  ��¼����        |  ������ |     4     |  ��λ����                   |
	% +----------------------------------------------------------------------+

	% ע0��  ��ʱΪ��digital event 1��(?) ��
	% ע1��  �ɷֱ�Ϊ0��1��2��3������0��ʾԭʼ��¼����̨����¼����δת����
	%        ͳһ��ĳһ���ͣ�ָ���ٶȡ��ٶȡ�λ�ƣ����¼�����������ԭʼ����
	%        �ļ���������̨ͬվ��¼���������Ͳ�ͬ������1ָ�¼��ļ�����ȫ��
	%        ���ٶ��ͣ�2ָ�¼��ļ�������ȫ���ٶ��ͣ�3ָ�¼��ļ�������ȫ��λ
	%        ���͵ģ��п����¼��ļ���¼�µľ����������ͣ�Ҳ�п�������ר�ŵ�
	%        Ӧ�ó���ת�������ġ�
	% ע2��  32λ�в�ͬλ��ʾ��ͬ�Ĵ��������ֶ����У�
	%        0x00000004        ����������Ч��
	%        0x00000008        ��������������ת
	%        0x00000010        �����������˲�
	%        0x00000020        ������ֱ��Ч��
	%        0x00000040        ����������Ч��



	% ����1.3   ̨�������ṹ (�ֳ� 96)
	% +----------------------------------------------------------------------+
	% |   �� Ŀ �� ��    |  �� ��  |  �� ��    |     ��      ע              |
	% +----------------------------------------------------------------------+
	% |   ̨ �� �� ��    |  �ַ��� |   80      |                             |
	% +----------------------------------------------------------------------+
	% |   ̨ վ �� ��    |  ������ |    4      |                             |
	% +----------------------------------------------------------------------+
	% |   �� �� γ ��    |  ������ |    4      |                             |
	% +----------------------------------------------------------------------+
	% |   �� �� �� ��    |  ������ |    4      |                             |
	% +----------------------------------------------------------------------+
	% |   �� �� �� ��    |  ������ |    4      |                             |
	% +----------------------------------------------------------------------+



	% ����1.4   ��������ṹ (�ֳ� 48)
	% +----------------------------------------------------------------------+
	% |   �� Ŀ �� ��    |  �� ��  |  �� ��    |     ��      ע              |
	% +----------------------------------------------------------------------+
	% |   �� �� ʱ ��    |  double |   8      |��ʽ��YYYYMMDDhhmmss.ss*      |
	% +----------------------------------------------------------------------+
	% |   �� �� γ ��    |  float  |    4     |                              |
	% +-----------------------
	-----------------------------------------------+
	% |   �� �� �� ��    |  float  |    4     |                              |
	% +----------------------------------------------------------------------+
	% |   �� Դ �� ��    |  float  |    4     |                              |
	% +----------------------------------------------------------------------+
	% |       Ml        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |       Md        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |       Ms        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |       Mb        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |      �� ��      |  char * |    12    |                               |
	% +----------------------------------------------------------------------+



	% ����1.5   ��������ṹ (�ֳ� 72)
	% +----------------------------------------------------------------------+
	% |   �� Ŀ �� ��    |  �� ��  |  �� ��    |     ��      ע              |
	% +----------------------------------------------------------------------+
	% |   ����Ա����     |  char  |   12      |                              |
	% +----------------------------------------------------------------------+
	% |   ����Ա���     |  long   |    4     |                              |
	% +----------------------------------------------------------------------+
	% |   ����ʱ����     |  long   |    4     |                              |
	% +----------------------------------------------------------------------+
	% |   ����ʱ��       |  double |    8     |                              |
	% +----------------------------------------------------------------------+
	% |    �� ��        |  float  |    44    |                               |
	% +----------------------------------------------------------------------+
	*/
	stringstream ss;
	//headerInfo.append(
	ss<<Convert2String(eventFileFlag, "�¼��ļ���־")   //|  �¼��ļ���־     |  �ַ��� |   16     | ��Ϊdigital event             |  ע0��  
	  <<Convert2String(recordMashineType, "��¼��������")   //|  ��¼��������      |  �ַ��� |   16     | PC �� Work Station            | 
	  <<Convert2String(recordFileType, "�ļ���¼����")      //|  �ļ���¼����      |  ����   |    4     | ע1��                         | 
	  <<Convert2String(dealHistory, "������")   //|  ������          |  ����   |    4     | ע2��                         | 
		<<Convert2String(netWideName, "̨������")   //|  ̨������          |  �ṹ   |    96    | �����̨������˵��            |  //   ̨������
		<<Convert2String(numberStation, "̨վ����")    //  ̨վ����
		<<Convert2String(centreLatitude, "����γ��")   //  ����γ��
		<<Convert2String(centreLongitude, "���ľ���")    //  ���ľ���  
		<<Convert2String(centreElevation, "���ĸ߳�")    //  ���ĸ߳�  
		<<Convert2String(origintime, "����ʱ��")    // |  �������         |  �ṹ   |    48    | �����                        |  // ����ʱ��
		<<Convert2String(epicentreLatitude, "����γ��")    //  ����γ��
		<<Convert2String(epicentreLongitude, "���о���")    //  ���о���
		<<Convert2String(hypocentreDepth, "��Դ���")   //  ��Դ��� 
		<<Convert2String(magnitudeMl, "Ml ��")       //   Ml 
		<<Convert2String(magnitudeMd, "Md ��")       //   Md 
		<<Convert2String(magnitudeMs, "Ms ��")       //   Ms 
		<<Convert2String(magnitudeMb, "Mb ��")      //   Mb 
		<<Convert2String(epicentreName, "�� ��")       //   �� ��
		<<Convert2String(operatorName, "����Ա����")
		<<Convert2String(operatorNumber, "����Ա���")   //  ����Ա���
		<<Convert2String(dealSecond, "����ʱ����")  //  ����ʱ����
		<<Convert2String(dealTime, "����ʱ��")    //  ����ʱ��
		<<Convert2String(reserved, "�� ��")     //  �� �� 
		<<"���ݿ�ʼʱ��: "
		<< daytime
		//HeaderInfo += Convert2String(daytime, "���ݿ�ʼʱ��"); // |  ���ݿ�ʼʱ��    |  ������  |    4     | ��1970-1-1 00:00:00��������� | 
		<<"\t(��1970-1-1 00:00:00���������)\n"
		<<Convert2String(year, "���ݿ�ʼʱ��: ��")  // |  ���ݿ�ʼʱ��    |  �ṹ    |    12    | �����������������ꡢ�¡��ա�  |   // ��
														// |                  |          |          |                ʱ���֡���     | 
		<<Convert2String(month, "              ��")  //  ��
		<<Convert2String(day, "              ��")    //  ��
		<<Convert2String(hour, "              ʱ")   //  ʱ
		<<Convert2String(minute, "              ��")  //  ��
		<<Convert2String(second, "              ��")   //  ��
		<<Convert2String(recordLength, " ��¼����")   //  |  ��¼����       |  ������   |     4    |  ��λ����                    |
		<<"\n";
	string str = ss.str();
	ss.clear();
	return str;
}

//��ʽ��toString()����
string EvtFileHeader::toStringForFile() {
	
	stringstream ss;
	//headerInfo.append(
	ss << Convert2String(eventFileFlag, "�¼��ļ���־")   //|  �¼��ļ���־     |  �ַ��� |   16     | ��Ϊdigital event             |  ע0��  
		<< Convert2String(recordMashineType, "��¼��������")   //|  ��¼��������      |  �ַ��� |   16     | PC �� Work Station            | 
		<< Convert2String(recordFileType, "�ļ���¼����")      //|  �ļ���¼����      |  ����   |    4     | ע1��                         | 
		<< Convert2String(dealHistory, "������")   //|  ������          |  ����   |    4     | ע2��                         | 
		<< Convert2String(netWideName, "̨������")   //|  ̨������          |  �ṹ   |    96    | �����̨������˵��            |  //   ̨������
		<< Convert2String(numberStation, "̨վ����")    //  ̨վ����
		<< Convert2String(centreLatitude, "����γ��")   //  ����γ��
		<< Convert2String(centreLongitude, "���ľ���")    //  ���ľ���  
		<< Convert2String(centreElevation, "���ĸ߳�")    //  ���ĸ߳�  
		<< Convert2String(origintime, "����ʱ��")    // |  �������         |  �ṹ   |    48    | �����                        |  // ����ʱ��
		<< Convert2String(epicentreLatitude, "����γ��")    //  ����γ��
		<< Convert2String(epicentreLongitude, "���о���")    //  ���о���
		<< Convert2String(hypocentreDepth, "��Դ���")   //  ��Դ��� 
		<< Convert2String(magnitudeMl, "Ml ��")       //   Ml 
		<< Convert2String(magnitudeMd, "Md ��")       //   Md 
		<< Convert2String(magnitudeMs, "Ms ��")       //   Ms 
		<< Convert2String(magnitudeMb, "Mb ��")      //   Mb 
		<< Convert2String(epicentreName, "�� ��")       //   �� ��
		<< Convert2String(operatorName, "����Ա����")
		<< Convert2String(operatorNumber, "����Ա���")   //  ����Ա���
		<< Convert2String(dealSecond, "����ʱ����")  //  ����ʱ����
		<< Convert2String(dealTime, "����ʱ��")    //  ����ʱ��
		<< Convert2String(reserved, "�� ��")     //  �� �� 
		<< "���ݿ�ʼʱ��: "
		<< daytime
		//HeaderInfo += Convert2String(daytime, "���ݿ�ʼʱ��"); // |  ���ݿ�ʼʱ��    |  ������  |    4     | ��1970-1-1 00:00:00��������� | 
		<< "\t(��1970-1-1 00:00:00���������)\n"
		<< Convert2String(year, "���ݿ�ʼʱ��: ��")  // |  ���ݿ�ʼʱ��    |  �ṹ    |    12    | �����������������ꡢ�¡��ա�  |   // ��
											  // |                  |          |          |                ʱ���֡���     | 
		<< Convert2String(month, "              ��")  //  ��
		<< Convert2String(day, "              ��")    //  ��
		<< Convert2String(hour, "              ʱ")   //  ʱ
		<< Convert2String(minute, "              ��")  //  ��
		<< Convert2String(second, "              ��")   //  ��
		<< Convert2String(recordLength, " ��¼����")   //  |  ��¼����       |  ������   |     4    |  ��λ����                    |
		<< "\n";
	string str = ss.str();
	ss.clear();
	return str;
}

//public end

//private
string EvtFileHeader::Convert2String(char * chars)
{
	//string str = new string(chars);
	//str.Remove(str.Length);
	//str += "\n";
	stringstream ss;
	string str(chars);
	//str.pop_back(); //ɾ�����һ��Ԫ��'\0'
	ss << chars << "\n";
	return ss.str();
}
string EvtFileHeader::Convert2String(char * chars, string Tips)
{
	//string str = new string(chars);
	//int strEnd = str.IndexOf('\0');
	//str = str.Remove(strEnd);
	//str = Tips + ": " + str + "\n";
	stringstream ss;
	ss << Tips << ": " << chars << "\n";
	return ss.str();
}

string EvtFileHeader::Convert2String(Int32 value)
{
	//string str = value.ToString() + "\n";
	//return str;
	stringstream ss; //Standard C++ Library
	ss << value << "\n";
	return ss.str();
}

string EvtFileHeader::Convert2String(Int32 value, string Tips)
{
	//string str = value.ToString();
	//str = Tips + ": " + str + "\n";
	//return str;
	stringstream ss; //Standard C++ Library
	ss << Tips << ": " << value << "\n";
	return ss.str();
}

string EvtFileHeader::EvtFileHeader::Convert2String(float value)
{
	//string str = value.ToString() + "\n";
	//return str;

	stringstream ss; //Standard C++ Library
	ss << value << "\n";
	return ss.str();
}

string EvtFileHeader::Convert2String(float value, string Tips)
{
	//string str = value.ToString();
	//str = Tips + ": " + str + "\n";
	stringstream ss;
	ss <<Tips << ": " << value << "\n";
	string str = ss.str();
	//Tips.append(": ");
	//str = Tips.append(str);
	return str;
}

string EvtFileHeader::Convert2String(double value)
{
	//string str = value.ToString() + "\n";
	stringstream ss;
	ss << value << "\n";
	string str = ss.str();
	return str;
}

string EvtFileHeader::Convert2String(double value, string Tips)
{
	//string str = value.ToString();
	//str = Tips + ": " + str + "\n";
	//return str;
	stringstream ss;
	ss << Tips << ": " << value << "\n";
	return ss.str();
}

string EvtFileHeader::Convert2String(short value)
{
	//string str = value.ToString() + "\n";
	//return str;
	stringstream ss;
	ss << value << "\n" << endl;
	return ss.str();
}

string EvtFileHeader::Convert2String(short value, string Tips)
{
	//string str = value.ToString();
	//str = Tips + ": " + str + "\n";
	//return str;
	stringstream ss;
	ss << Tips << ": " << value << "\n";
	return ss.str();
}









