// GetWaves.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dirread.h"
#include <string>
#include "EvtFileHeader.h"
#include "SingleStation.h"
#include "EvtFileProcessing.h"
#include "TxtWrite.h"
#include <iostream>
#include "MathUtils.h"
#include <bitset>
#include <cstdio>
#include <thread>

using namespace std;

void thread_oprator(string read_dir, string write_dir, const string & filename) {
	string str = filename;
	string read_evt(read_dir);
	read_evt.append(str);
	cout << "read file..." << read_evt << endl;

	EvtFileHeader evtFileHeader;
	SingleStation singleStation;
	EvtFileProcessing evtFileProcessing;


	str = str.erase(str.find_first_of('.', '\0'), str.size());
	str = str.append(".txt");
	string write_txt = write_dir.append(str);
	TxtWrite tw(write_txt);
	cout << "cun: " << write_txt << endl;
	evtFileProcessing.setEvtFileName(read_evt);
	evtFileProcessing.readData(2200); //ȫ���� //410�룬20000��
	cout << "read complete..." << "\t" << filename<< endl;
	evtFileProcessing.writeData(tw);
}



int main(int argc, char** argv)
{
	string read_dir("E:/seismic-data/����Ȼevt/");
	string write_dir("E:/seismic-data/feitianran_txt/");
	cout << "������Ҫ��ȡ�ĵ����ļ�evt�ļ���Ŀ¼(��'\\'��β)" << "\n\t\t�Կո����"\
		 << "\n������Ҫת���txt���ļ���Ŀ¼(��'\\'��β)" << endl;

	//cin >> read_dir >> write_dir;
	

	cout << "��ʼִ�в���" << endl;
	
	
	vector<string> filenames;

	//��ȡ���е��ļ����������ļ����ļ�  
	//GetAllFiles(read_dir, filenames);  

	//��ȡ���и�ʽΪevt���ļ�  
	string format = ".evt";
	DirRead::GetAllFormatFiles(read_dir, filenames, format);
	int length = filenames.size();
	if (4 < length) {
		for (int i = 0; i < length; i++) {
			//thread_oprator(read_dir, write_dir, filenames[i]);
			std::thread t(thread_oprator, read_dir, write_dir, filenames[i]);
			t.join();

		}
	}
	else {
		int frames = length / 4;
		int shengyu = length - 4 * frames;
		for (int j = 0; j < frames; j++) {
			for (int i = 4 * j; i < 4 * (j + 1); i++) {
				std::thread t(thread_oprator, read_dir, write_dir, filenames[i]);
						t.join();
			}
		}
		for (int i = length - shengyu; i < length; i++) {
			std::thread t(thread_oprator, read_dir, write_dir, filenames[i]);
			t.join();
		}
	}
	/*
	for (int i = 0; i < filenames.size(); i++) {
		thread_oprator(read_dir, write_dir, filenames[i]);
	}
	*/
	system("pause");
    return 0;
}


int main_copy2() {
	string read_dir("E:/seismic-data/��������2010/��Ȼevt/");
	string write_dir("E:/");
	thread_oprator(read_dir, write_dir, "20080429042921-1.evt");
	//t.join();
	return 0;
}

int main_copy(int argc, char** argv)
{
	//EvtFileHeader evtFileHeader;
	//SingleStation singleStation;
	//EvtFileProcessing evtFileProcessing;
	//TxtWrite tw("E:/seismic-data/20051120225337.txt");
	//string s1("E:/����ʶ��/Seismology/ExplosionEarthquakeRecognition/ExplosionEarthquakeRecognition/WavesData/Explosions/20020515223223-1.evt");
	//string s1("E:/seismic-data/20051120225337.evt");
	//ifstream ifs("E:/����ʶ��/Seismology/ExplosionEarthquakeRecognition/ExplosionEarthquakeRecognition/WavesData/Explosions/20020515223223-1.evt", ios::binary | ios::in); //ֻ��ģʽ,�������ļ�����
	//ifstream ifs("D://1.txt", ios::binary | ios::in);

	//ifs.seekg(0, ios::beg);  //ios::beg�ļ���ͷ�� ios::cur�ļ���ǰλ��  ios::end�ļ���β
	//evtFileHeader.readHeader(ifs); //�����ļ�ͷ
	//cout << evtFileHeader.toString();
	//ifs.seekg(276, ios::beg);
	//singleStation.read(ifs);
	//evtFileProcessing.setEvtFileName(s1);
	//evtFileProcessing.readData();
	//cout << "read complete..." << endl;
	//evtFileProcessing.writeData(tw);
	//tw.write(evtFileProcessing.toStringWaveData());

	//string s2 = evtFileProcessing.toString();   //singleStation.toStringByStation().c_str();
	//cout << s2 << endl;
	//cout << s2 << endl;

	//ifs.close(); // �ر��ļ�
	//cout << MathUtils::toInt(temp);
	/*
	ifs.seekg(40, ios::cur);
	char * value = new char[5];
	value[4] = '\0';
	ifs.read(value, 4);
	int ch1 = value[3];
	unsigned int ch2 = value[2];
	unsigned int ch3 = value[1];
	unsigned int ch4 = value[0];

	//if ((ch1 | ch2 | ch3 | ch4) < 0)
	//return -1;
	cout << ch1 << " " << ch2 << " " << ch3 << " " << ch4 << endl;
	ch1 = ch1 << 24;

	ch2 = ch2 << 24;
	ch2 = ch2 >> 8;

	ch3 = ch3 << 24;
	ch3 = ch3 >> 16;

	ch4 = ch4 << 24;
	ch4 = ch4 >> 24;
	int ch = ch1 + ch2 + ch3 + ch4;
	cout << "ch: " << ch << endl;
	bitset<32> b1(ch);
	cout <<"b1: " << b1 << endl;
	*/
	//cout << "////////////////////////////////////////" << endl;
	//cout << "sizof(float): " << sizeof(float) << endl;
	//cout << "sizof(__int32): " << sizeof(__int32) << endl;
	//cout << "sizof(double): " << sizeof(double) << endl;
	//cout << "sizof(short): " << sizeof(short) << endl;
	//cout << "sizof(char): " << sizeof(char) << endl;
	//cout << "sizeof(long long): " << sizeof(long long) << endl;
	//tw.write(s2);cout << "111" << endl;
	//argc ��ָ��������������ĸ���(�Կհ׷��ָ�) argv�洢�����е������в���
	cout << "������Ҫ��ȡ�ĵ����ļ�evt�ļ���Ŀ¼" << "\n\t\t�Կո����"\
		<< "\n������Ҫת���txt���ļ���Ŀ¼" << endl;
	string read_dir(argv[1]);
	string write_dir(argv[2]);
	if (read_dir.empty() && write_dir.empty()) {
		read_dir.assign("E:/EVT/��Ȼ����_EVT");
		write_dir.assign("E:/EVT/tianran_txt123/");
	}

	vector<string> filenames;

	//��ȡ���е��ļ����������ļ����ļ�  
	//GetAllFiles(read_dir, filenames);  

	//��ȡ���и�ʽΪevt���ļ�  
	string format = ".evt";
	DirRead::GetAllFormatFiles(read_dir, filenames, format);
	for (int i = 0; i < filenames.size(); i++) {
		std::thread t(thread_oprator, read_dir, write_dir, filenames[i]);
		t.join();
		/*
		string str = filenames[i];
		string read_evt(read_dir);
		read_evt.append(str);
		cout << "read file..." << read_evt << endl;

		EvtFileHeader evtFileHeader;
		SingleStation singleStation;
		EvtFileProcessing evtFileProcessing;


		str = str.erase(str.find_first_of('.', '\0'), str.size());
		str = str.append(".txt");
		string write_txt = write_dir.append(str);
		TxtWrite tw(write_txt);
		cout << "cun: " << write_txt << endl;
		evtFileProcessing.setEvtFileName(read_evt);
		evtFileProcessing.readData();
		cout << "read complete..."<< "\t" << filenames[i]<< endl;
		evtFileProcessing.writeData(tw);
		*/

	}
	system("pause");
	return 0;
}
