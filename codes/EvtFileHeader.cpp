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

//海拔
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
	//如果文件不存在，返回void，函数不进行处理
	if (!fstream(this->eventFileName))  //	 evtFileName))//File.Exists(EvtFileName))
	{
		string ErrorMessage = "文件不存在!";
		//throw ErrorMessage; //抛出异常
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
	message = string.Format("打开文件\"%s\"时出错！    \n\n本软件目前尚不认识该数据文件的格式。  \n请尝试选择其他数据文件。  ", EvtFileName);
	MessageBox.Show(message);
	binReader.Close();
	fstream.Close();
	return;
	}
	*/

	//以二进制打开文件
	ifstream ifs(this->eventFileName, ios::in | ios::binary, 0);//0只读方式打开，2隐含文件，4系统文件
	ifs.seekg(0, ios::beg);
	char * temp = new char[16];
	ifs.read(temp, 16); //读取16个字符
	this->eventFileName = string(temp);

	string message;

	//如果字符串相等,则表明不识别该文件
	if (string(eventFileFlag).compare("digital event") == 0)
	{
		message = string("打开文件");//\"%s\//
		message.append(this->eventFileName);
		message.append("时出错！    \n\n本软件目前尚不认识该数据文件的格式。  \n请尝试选择其他数据文件。  ");

		//message = string.Format("打开文件\"%s\"时出错！    \n\n本软件目前尚不认识该数据文件的格式。  \n请尝试选择其他数据文件。  ", EvtFileName);
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
	delete temp; // 释放前面的new temp[16]

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

	ifs.close(); // 关闭文件
	
}


/*
void EvtFileHeader::readHeader(ifstream & ifs) {
	ifs.seekg(0, ios::beg);
	ifs.read(eventFile, 16); //读取16个字符
	//this->eventFileName = string(temp);
	//cout << eventFile << endl;
	//如果字符串相等,则表明不识别该文件
	if (this->eventFileFlag.compare("digital event") == 0)
	{
		string message("打开文件");  //\"%s\//
		message.append(this->eventFileName);
		message.append("时出错！    \n\n本软件目前尚不认识该数据文件的格式。  \n请尝试选择其他数据文件。  ");

		//message = string.Format("打开文件\"%s\"时出错！    \n\n本软件目前尚不认识该数据文件的格式。  \n请尝试选择其他数据文件。  ", EvtFileName);
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

	ifs.close(); // 关闭文件

}
*/

void EvtFileHeader::readHeader(ifstream & ifs) {
	//ifs.clear();
	ifs.seekg(0, ios::beg);
	ifs.read(eventFileFlag, 16); //读取16个字符
	//如果字符串相等,则表明不识别该文件
	if (string(eventFileFlag).compare("digital event") != 0)
	{
		string message("打开文件");  //\"%s\//
		message.append(this->eventFileName);
		message.append("时出错！    \n\n本软件目前尚不认识该数据文件的格式。  \n请尝试选择其他数据文件。  ");

		//message = string.Format("打开文件\"%s\"时出错！    \n\n本软件目前尚不认识该数据文件的格式。  \n请尝试选择其他数据文件。  ", EvtFileName);
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
	//ifs.read(eventFileFlag, 16); //读取16个字符
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
	% 附录：  交互分析系统的输入输出文件说明
	% 附表一、事件数据文件结构
	% 附表1.1   事件数据文件总体结构示意
	%   如下图所示， 事件文件由三个部分组成，它们分别是事件头、台站参数和波形数据，
	%   其各部分具体结构祥见后面有关图表。
	%                     ┏━━━━━━━━━━━━━━━━━┓
	%                     ┃     事 件 头                     ┃
	%                     ┣━━━━━━━━━━━━━━━━━┫
	%                     ┃     第一个台站参数            　 ┃
	%                     ┠─────────────────┨
	%                     ┃     第一通道参数              　 ┃
	%                     ┃     [第二通道参数                ┃
	%                     ┃        : ]                       ┃
	%                     ┠─────────────────┨
	%                     ┃     第二个台站参数            　 ┃
	%                     ┠─────────────────┨
	%                     ┃     第一通道参数            　   ┃
	%                     ┃     [第二通道参数                ┃
	%                     ┃        : ]                       ┃
	%                     ┠─────────────────┨
	%                     ┃         :                        ┃
	%                     ┠─────────────────┨
	%                     ┃     第N个台站参数           　   ┃
	%                     ┠─────────────────┨
	%                     ┃     第一通道参数            　   ┃
	%                     ┃     [第二通道参数                ┃
	%                     ┃        : ]                       ┃
	%                     ┣━━━━━━━━━━━━━━━━━┫
	%                     ┃     第一个台站数据           　  ┃ 第一秒 开始处
	%                     ┠─────────────────┨
	%                     ┃     [第二个台站数据          　  ┃
	%                     ┠─────────────────┨
	%                     ┃          :                    　 ┃
	%                     ┠─────────────────┨
	%                     ┃     第N个台站数据]            　 ┃第一秒 结束处
	%                     ┠─────────────────┨
	%                     ┃     {第一个台站数据            　┃ 第二秒 开始处
	%                     ┠─────────────────┨
	%                     ┃     [第二个台站数据          　  ┃
	%                     ┠─────────────────┨
	%                     ┃          :                  　   ┃
	%                     ┠─────────────────┨
	%                     ┃     第N个台站数据]            　 ┃第二秒 结束处
	%                     ┠─────────────────┨
	%                     ┃          :                    　 ┃
	%                     ┃          :                    　 ┃
	%                     ┠─────────────────┨
	%                     ┃     第一个台站数据             　┃ 最后一秒 开始处
	%                     ┠─────────────────┨
	%                     ┃     [第二个台站数据           　 ┃
	%                     ┠─────────────────┨
	%                     ┃          :                    　 ┃
	%                     ┠─────────────────┨
	%                     ┃     第N个台站数据]}            　┃　最后一秒 结束处
	%                     ┗━━━━━━━━━━━━━━━━━┛



	% 附表1.2   事件记录头数据结构 (总字长 276 =  16+16+4+4+96+48+72+4+12+4)
	% +----------------------------------------------------------------------+
	% |   项 目 名 称    |  类 型  |  字 长    |     备      注              |
	% +----------------------------------------------------------------------+
	% |  事件文件标志    |  字符串 |   16      | 恒为digital event    注0）  |
	% +----------------------------------------------------------------------+
	% |  记录主机类型    |  字符串 |   16      | PC 或 Work Station          |
	% +----------------------------------------------------------------------+
	% |  文件记录类型    |  整型   |    4      | 注1）                       |
	% +----------------------------------------------------------------------+
	% |  处理经历        |  整型   |    4      | 注2）                       |
	% +----------------------------------------------------------------------+
	% |  台网参数        |  结构   |    96     | 祥见后台网参数说明          |
	% +----------------------------------------------------------------------+
	% |  地震参数        |  结构   |    48     | 祥见后                      |
	% +----------------------------------------------------------------------+
	% |  分析管理信息    |  结构   |    72     | 祥见后                      |
	% +----------------------------------------------------------------------+
	% |  数据开始时间    |  长整型 |    4     | 从1970-1-1 00:00:00起算的秒数|
	% +----------------------------------------------------------------------+
	% |  数据开始时间    |  结构   |     12    | 六个短整数，依次年、月、日、|
	% |                  |         |           |                时、分、秒   |
	% +----------------------------------------------------------------------+
	% |  记录长度        |  长整型 |     4     |  单位：秒                   |
	% +----------------------------------------------------------------------+

	% 注0）  有时为“digital event 1”(?) 。
	% 注1）  可分别为0，1，2，3，其中0表示原始记录，即台网记录下来未转换成
	%        统一的某一类型（指加速度、速度、位移）的事件，这样，在原始数据
	%        文件中是允许不同台站记录的数据类型不同。其它1指事件文件数据全是
	%        加速度型，2指事件文件的数据全是速度型，3指事件文件的数据全是位
	%        移型的，有可能事件文件记录下的就是这种类型，也有可能是用专门的
	%        应用程序转换而来的。
	% 注2）  32位中不同位表示不同的处理经历，现定义有：
	%        0x00000004        经过了仪器效正
	%        0x00000008        经过了坐标轴旋转
	%        0x00000010        经过了数字滤波
	%        0x00000020        经过了直流效正
	%        0x00000040        经过了线性效正



	% 附表1.3   台网参数结构 (字长 96)
	% +----------------------------------------------------------------------+
	% |   项 目 名 称    |  类 型  |  字 长    |     备      注              |
	% +----------------------------------------------------------------------+
	% |   台 网 名 称    |  字符串 |   80      |                             |
	% +----------------------------------------------------------------------+
	% |   台 站 总 数    |  长整型 |    4      |                             |
	% +----------------------------------------------------------------------+
	% |   中 心 纬 度    |  浮点数 |    4      |                             |
	% +----------------------------------------------------------------------+
	% |   中 心 经 度    |  浮点数 |    4      |                             |
	% +----------------------------------------------------------------------+
	% |   中 心 高 程    |  浮点数 |    4      |                             |
	% +----------------------------------------------------------------------+



	% 附表1.4   地震参数结构 (字长 48)
	% +----------------------------------------------------------------------+
	% |   项 目 名 称    |  类 型  |  字 长    |     备      注              |
	% +----------------------------------------------------------------------+
	% |   发 震 时 刻    |  double |   8      |格式：YYYYMMDDhhmmss.ss*      |
	% +----------------------------------------------------------------------+
	% |   震 中 纬 度    |  float  |    4     |                              |
	% +-----------------------
	-----------------------------------------------+
	% |   震 中 经 度    |  float  |    4     |                              |
	% +----------------------------------------------------------------------+
	% |   震 源 深 度    |  float  |    4     |                              |
	% +----------------------------------------------------------------------+
	% |       Ml        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |       Md        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |       Ms        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |       Mb        |  float  |    4     |                               |
	% +----------------------------------------------------------------------+
	% |      地 名      |  char * |    12    |                               |
	% +----------------------------------------------------------------------+



	% 附表1.5   分析管理结构 (字长 72)
	% +----------------------------------------------------------------------+
	% |   项 目 名 称    |  类 型  |  字 长    |     备      注              |
	% +----------------------------------------------------------------------+
	% |   操作员姓名     |  char  |   12      |                              |
	% +----------------------------------------------------------------------+
	% |   操作员编号     |  long   |    4     |                              |
	% +----------------------------------------------------------------------+
	% |   处理时间秒     |  long   |    4     |                              |
	% +----------------------------------------------------------------------+
	% |   处理时间       |  double |    8     |                              |
	% +----------------------------------------------------------------------+
	% |    保 留        |  float  |    44    |                               |
	% +----------------------------------------------------------------------+
	*/
	stringstream ss;
	//headerInfo.append(
	ss<<Convert2String(eventFileFlag, "事件文件标志")   //|  事件文件标志     |  字符串 |   16     | 恒为digital event             |  注0）  
	  <<Convert2String(recordMashineType, "记录主机类型")   //|  记录主机类型      |  字符串 |   16     | PC 或 Work Station            | 
	  <<Convert2String(recordFileType, "文件记录类型")      //|  文件记录类型      |  整型   |    4     | 注1）                         | 
	  <<Convert2String(dealHistory, "处理经历")   //|  处理经历          |  整型   |    4     | 注2）                         | 
		<<Convert2String(netWideName, "台网名称")   //|  台网参数          |  结构   |    96    | 祥见后台网参数说明            |  //   台网名称
		<<Convert2String(numberStation, "台站总数")    //  台站总数
		<<Convert2String(centreLatitude, "中心纬度")   //  中心纬度
		<<Convert2String(centreLongitude, "中心经度")    //  中心经度  
		<<Convert2String(centreElevation, "中心高程")    //  中心高程  
		<<Convert2String(origintime, "发震时刻")    // |  地震参数         |  结构   |    48    | 祥见后                        |  // 发震时刻
		<<Convert2String(epicentreLatitude, "震中纬度")    //  震中纬度
		<<Convert2String(epicentreLongitude, "震中经度")    //  震中经度
		<<Convert2String(hypocentreDepth, "震源深度")   //  震源深度 
		<<Convert2String(magnitudeMl, "Ml 震级")       //   Ml 
		<<Convert2String(magnitudeMd, "Md 震级")       //   Md 
		<<Convert2String(magnitudeMs, "Ms 震级")       //   Ms 
		<<Convert2String(magnitudeMb, "Mb 震级")      //   Mb 
		<<Convert2String(epicentreName, "地 名")       //   地 名
		<<Convert2String(operatorName, "操作员姓名")
		<<Convert2String(operatorNumber, "操作员编号")   //  操作员编号
		<<Convert2String(dealSecond, "处理时间秒")  //  处理时间秒
		<<Convert2String(dealTime, "处理时间")    //  处理时间
		<<Convert2String(reserved, "保 留")     //  保 留 
		<<"数据开始时间: "
		<< daytime
		//HeaderInfo += Convert2String(daytime, "数据开始时间"); // |  数据开始时间    |  长整型  |    4     | 从1970-1-1 00:00:00起算的秒数 | 
		<<"\t(从1970-1-1 00:00:00起算的秒数)\n"
		<<Convert2String(year, "数据开始时间: 年")  // |  数据开始时间    |  结构    |    12    | 六个短整数，依次年、月、日、  |   // 年
														// |                  |          |          |                时、分、秒     | 
		<<Convert2String(month, "              月")  //  月
		<<Convert2String(day, "              日")    //  日
		<<Convert2String(hour, "              时")   //  时
		<<Convert2String(minute, "              分")  //  分
		<<Convert2String(second, "              秒")   //  秒
		<<Convert2String(recordLength, " 记录长度")   //  |  记录长度       |  长整型   |     4    |  单位：秒                    |
		<<"\n";
	string str = ss.str();
	ss.clear();
	return str;
}

//形式与toString()类似
string EvtFileHeader::toStringForFile() {
	
	stringstream ss;
	//headerInfo.append(
	ss << Convert2String(eventFileFlag, "事件文件标志")   //|  事件文件标志     |  字符串 |   16     | 恒为digital event             |  注0）  
		<< Convert2String(recordMashineType, "记录主机类型")   //|  记录主机类型      |  字符串 |   16     | PC 或 Work Station            | 
		<< Convert2String(recordFileType, "文件记录类型")      //|  文件记录类型      |  整型   |    4     | 注1）                         | 
		<< Convert2String(dealHistory, "处理经历")   //|  处理经历          |  整型   |    4     | 注2）                         | 
		<< Convert2String(netWideName, "台网名称")   //|  台网参数          |  结构   |    96    | 祥见后台网参数说明            |  //   台网名称
		<< Convert2String(numberStation, "台站总数")    //  台站总数
		<< Convert2String(centreLatitude, "中心纬度")   //  中心纬度
		<< Convert2String(centreLongitude, "中心经度")    //  中心经度  
		<< Convert2String(centreElevation, "中心高程")    //  中心高程  
		<< Convert2String(origintime, "发震时刻")    // |  地震参数         |  结构   |    48    | 祥见后                        |  // 发震时刻
		<< Convert2String(epicentreLatitude, "震中纬度")    //  震中纬度
		<< Convert2String(epicentreLongitude, "震中经度")    //  震中经度
		<< Convert2String(hypocentreDepth, "震源深度")   //  震源深度 
		<< Convert2String(magnitudeMl, "Ml 震级")       //   Ml 
		<< Convert2String(magnitudeMd, "Md 震级")       //   Md 
		<< Convert2String(magnitudeMs, "Ms 震级")       //   Ms 
		<< Convert2String(magnitudeMb, "Mb 震级")      //   Mb 
		<< Convert2String(epicentreName, "地 名")       //   地 名
		<< Convert2String(operatorName, "操作员姓名")
		<< Convert2String(operatorNumber, "操作员编号")   //  操作员编号
		<< Convert2String(dealSecond, "处理时间秒")  //  处理时间秒
		<< Convert2String(dealTime, "处理时间")    //  处理时间
		<< Convert2String(reserved, "保 留")     //  保 留 
		<< "数据开始时间: "
		<< daytime
		//HeaderInfo += Convert2String(daytime, "数据开始时间"); // |  数据开始时间    |  长整型  |    4     | 从1970-1-1 00:00:00起算的秒数 | 
		<< "\t(从1970-1-1 00:00:00起算的秒数)\n"
		<< Convert2String(year, "数据开始时间: 年")  // |  数据开始时间    |  结构    |    12    | 六个短整数，依次年、月、日、  |   // 年
											  // |                  |          |          |                时、分、秒     | 
		<< Convert2String(month, "              月")  //  月
		<< Convert2String(day, "              日")    //  日
		<< Convert2String(hour, "              时")   //  时
		<< Convert2String(minute, "              分")  //  分
		<< Convert2String(second, "              秒")   //  秒
		<< Convert2String(recordLength, " 记录长度")   //  |  记录长度       |  长整型   |     4    |  单位：秒                    |
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
	//str.pop_back(); //删除最后一个元素'\0'
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









