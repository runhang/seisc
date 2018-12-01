#pragma once
#ifndef EVTFILEPEOCESSING_H
#define EVTFILEPEOCESSING_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "txtwrite.h"

using namespace std;

//EvtFileHeader
//EvtFileProcessing_Libraray
#include "EvtFileHeader.h"
#include "SingleStation.h"


class EvtFileProcessing
{
public:
	static long badDataCounts; // inisize is 0

	EvtFileProcessing();
	~EvtFileProcessing();

	// set and get function
    // set function
	void setEvtFileName(string & evtFileName);

	//get function
	string getEvtFileName();
	
	//end set and get function

	void readAllData();
	void readData(const int& samples_length);
	void writeData(TxtWrite& tw);

	vector<double> & EvtFileProcessing::getSingleWave(string & fileName, int & stationNumber, int & channelNumber);

	string toString();

	string toStringWaveData();

	string toStringForStationNumber(int begin, int stationNumber);

protected:

private:

	EvtFileHeader evtFileHeader;  //evt头文件
	vector<SingleStation> singleStations;    //台站
	//vector<SingleChannel> WaveData = new List<SingleChannel>();
	string evtFileName;   //evt File Name
	bool isEvtFileOpen = false;
	//Form host;
	//ProgressBar progressBar1 = new ProgressBar();
	//ToolStripProgressBar toolstrip_progressBar1 = new ToolStripProgressBar();
	
	void readStations(ifstream & ifs);   //读台站


	void readWaveData(ifstream & ifs, int read_length);   //读波, read_length为读取波的点数，read_length==0,读取波的全波点数

	void clear();

};


#endif