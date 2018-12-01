#pragma once

#ifndef EVTFILEHEADER_H
#define EVTFILEHEADER_H

#define Int32 __int32


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "mathUtils.h"

using namespace std;

class EvtFileHeader
{
	//struct _EvtHeader
	//{
public:
	//_EvtHeader EvtHeader;

	//Constructor
	EvtFileHeader();

	EvtFileHeader(string & fileName);
	void read();

	void readHeader(ifstream & ifs);

	string toString();
	string toStringForFile();
	~EvtFileHeader();



	/**
	* .h文件描述
	*/
	//get and set function
	//string getEventFile();  // = new char[16];
	string getRecordMashineType();  //= new char[16];
	Int32 getRecordFileType(); //Int32
	int getDealHistory(); //Int32
	string getNetWideName(); // = new char[80];
	Int32 getNumberStation(); //Int32 
	float getCentreLatitude();
	float getCentreLongitude();
	float getCentreElevation();
	double getOrigintime();
	float getEpicentrelatitude();
	float getEpicentreLongitude();
	float getHypocentreDepth();
	float getMagnitudeMl();   //震级Ml
	float getMagnitudeMd();  //震级Md
	float getMagnitudeMs();  //震级Ms
	float getMagnitudeMb();  //震级Ms
	string getEpicentreName(); // 
	string getOperatorName(); // 
	Int32 getOperatorNumber(); //Int32
	Int32 getDealSecond(); //Int32
	double getDealTime();  //处理时间
	string getReserved();  // = new char[44];
	Int32 getDaytime();   //Int32
	short getYear();
	short getMonth();
	short getDay();
	short getHour();
	short getMinute();
	short getSecond();
	Int32 getRecordLength();  //Int32

	string getEventFileName();
	string getEventFileFlag();

	//set function
	void setEventFile(string value); // = new char[16];
	void setRecordMashineType(string value);  //= new char[16];
	void setRecordFileType(Int32 value); //Int32
	void setDealHistory(Int32 value); //Int32
	void setNetWideName(string value); // = new char[80];
	void setNumberStation(Int32 value); //Int32 
	void setCentreLatitude(float value);
	void setCentreLongitude(float value);
	void setCentreElevation(float value);
	void setOrigintime(double value);
	void setEpicentreLatitude(float value);
	void setEpicentreLongitude(float value);
	void setHypocentreDepth(float value);
	void setMagnitudeMl(float value);   //震级Ml
	void setMagnitudeMd(float value);  //震级Md
	void setMagnitudeMs(float value);  //震级Ms
	void setMagnitudeMb(float value);  //震级Ms
	void setEpicentreName(float value); // 
	void setOperatorName(float value); // 
	void setOperatorNumber(Int32 value); //Int32
	void setDealSecond(Int32 value); //Int32
	void setDealTime(double value);  //处理时间
	void setReserved(string value);  // = new char[44];
	void setDaytime(Int32 value);   //Int32
	void setYear(short value);
	void setMonth(short value);
	void setDay(short value);
	void setHour(short value);
	void setMinute(short value);
	void setSecond(short value);
	void setRecordLength(Int32 value);  //Int32
	void setEventFileName(string & value);
	//void setEventFileFlag(string & value);
	//public function


private:
	char * eventFileFlag = new char[16 + 1];//[16]; // = new char[16];
	char * recordMashineType = new char[16 + 1];//[16];  //= new char[16];
	Int32 recordFileType; //Int32
	int dealHistory; //Int32
	char * netWideName = new char[80 + 1];; // = new char[80];
	Int32 numberStation; //Int32 
	float centreLatitude;
	float centreLongitude;
	float centreElevation;
	double origintime;
	float epicentreLatitude;
	float epicentreLongitude;
	float hypocentreDepth;
	float magnitudeMl;   //震级Ml
	float magnitudeMd;  //震级Md
	float magnitudeMs;  //震级Ms
	float magnitudeMb;  //震级Ms
	char * epicentreName = new char[12 + 1]; // = new char[12];
	char * operatorName = new char[12 + 1]; // = new char[12];
						   //byte[] epicname = new byte[12];
						   //byte[] op_name = new byte[12];
	Int32 operatorNumber; //Int32
	Int32 dealSecond; //Int32
	double dealTime;  //处理时间
	char* reserved = new char[44 + 1];  // = new char[44];
	Int32 daytime;   //Int32
	short year;
	short month;
	short day;
	short hour;
	short minute;
	short second;
	Int32 recordLength;  //Int32
						 //};


	/////////////////////////////////
	string eventFileName;

	std::string Convert2String(char* chars);
	std::string Convert2String(char* chars, string Tips);
	std::string Convert2String(Int32 value);
	std::string Convert2String(Int32 value, string Tips);
	std::string Convert2String(float value);
	std::string Convert2String(float value, string Tips);
	std::string Convert2String(double value);
	std::string Convert2String(double value, string Tips);
	std::string Convert2String(short value);
	std::string Convert2String(short value, string Tips);


	/*.h文件描述结尾*/

};
	
#endif
