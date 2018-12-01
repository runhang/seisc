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

	EvtFileHeader evtFileHeader;  //evtͷ�ļ�
	vector<SingleStation> singleStations;    //̨վ
	//vector<SingleChannel> WaveData = new List<SingleChannel>();
	string evtFileName;   //evt File Name
	bool isEvtFileOpen = false;
	//Form host;
	//ProgressBar progressBar1 = new ProgressBar();
	//ToolStripProgressBar toolstrip_progressBar1 = new ToolStripProgressBar();
	
	void readStations(ifstream & ifs);   //��̨վ


	void readWaveData(ifstream & ifs, int read_length);   //����, read_lengthΪ��ȡ���ĵ�����read_length==0,��ȡ����ȫ������

	void clear();

};


#endif