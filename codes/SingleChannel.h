#pragma once
#ifndef SINGLECHANNEL_H
#define SINGLECHANNEL_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <cmath>
#include "MathUtils.h"


using namespace std;

#define Int32 __int32

class SingleChannel
{
public:
	// Constructor
	SingleChannel(string & fileName);
	SingleChannel(const SingleChannel & singleChannel); // 构造函数
	void operator=(const SingleChannel & singleChannel);
	~SingleChannel();
	//set and get function
	//set function
	void setChannelName(const char * value);
	void setChannelNumber(const Int32 & value);
	void setGain(const float & value);
	void setResonseOrder(const Int32 & value);
	void setResponseType(const Int32 & value);
	void setFrequenceNumber(const Int32 & value);
	void setWaveData(const vector<float> & value);
	void setEventFileName(const string & value);
	void setStrForTxt(const string & value);
	void setContinuePointSec(const int &value);

	// get function
	string getEventFileName() const;
	string getChannelName() const;
	Int32 getChannelNumber() const;
	float getGain() const;
	Int32 getResponseOrder() const;
	Int32 getResponseType() const;
	Int32 getFrequenceNumber() const;
	int getContinuePointSec() const;

	vector<float> getWaveData() const;
	string getStrForTxt() const;

	void read(ifstream & ifs);

	void readData(ifstream & ifs, int Count, bool Is4Bytes);

	void clear();

	string toString();

	string toStringOnlyChannel();

	string toWaveDataOnlyCHannelToFile();



protected:


private:
	char* channelName; // = new char[12 + 1];     //|   通道名称   |  字符串  |   12   |    |  
	Int32 channelNumber;      //|   通道编号   |  整型    |   4    |    |  
	float gain;               //|   增益因子   |  浮点    |   4    |    |  
	Int32 responseOrder;      //|   响应阶数   |  整型    |   4    |    |  
	Int32 responseType;       //|   响应类型   |  整型    |   4    |    |  
	Int32 frequenceNumber;    //|   频率数目   |  整型    |   4    |    |  
							  //byte[] status = new byte[12280];  //| |  |   12280    |   

	int continuePointSec; // 连续点数的秒数描述记录

	string eventFileName;
	vector<float> waveData;
	string strForTxt;  //存储读入txt文件的方式

	char * shortTemp;      // = new char[2 + 1]; // short缓存
	char* intTemp;         // = new char[4 + 1];
	char * floatTemp;      // = new char[4 + 1];
};

#endif


