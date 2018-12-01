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
	evtFileProcessing.readData(2200); //全序列 //410秒，20000点
	cout << "read complete..." << "\t" << filename<< endl;
	evtFileProcessing.writeData(tw);
}



int main(int argc, char** argv)
{
	string read_dir("E:/seismic-data/非天然evt/");
	string write_dir("E:/seismic-data/feitianran_txt/");
	cout << "请输入要读取的地震文件evt文件夹目录(以'\\'结尾)" << "\n\t\t以空格隔开"\
		 << "\n请输入要转存成txt的文件夹目录(以'\\'结尾)" << endl;

	//cin >> read_dir >> write_dir;
	

	cout << "开始执行操作" << endl;
	
	
	vector<string> filenames;

	//读取所有的文件，包括子文件的文件  
	//GetAllFiles(read_dir, filenames);  

	//读取所有格式为evt的文件  
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
	string read_dir("E:/seismic-data/波形数据2010/天然evt/");
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
	//string s1("E:/地震识别/Seismology/ExplosionEarthquakeRecognition/ExplosionEarthquakeRecognition/WavesData/Explosions/20020515223223-1.evt");
	//string s1("E:/seismic-data/20051120225337.evt");
	//ifstream ifs("E:/地震识别/Seismology/ExplosionEarthquakeRecognition/ExplosionEarthquakeRecognition/WavesData/Explosions/20020515223223-1.evt", ios::binary | ios::in); //只读模式,二进制文件读入
	//ifstream ifs("D://1.txt", ios::binary | ios::in);

	//ifs.seekg(0, ios::beg);  //ios::beg文件开头。 ios::cur文件当前位置  ios::end文件结尾
	//evtFileHeader.readHeader(ifs); //读入文件头
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

	//ifs.close(); // 关闭文件
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
	//argc 是指命令行输入参数的个数(以空白符分隔) argv存储了所有的命令行参数
	cout << "请输入要读取的地震文件evt文件夹目录" << "\n\t\t以空格隔开"\
		<< "\n请输入要转存成txt的文件夹目录" << endl;
	string read_dir(argv[1]);
	string write_dir(argv[2]);
	if (read_dir.empty() && write_dir.empty()) {
		read_dir.assign("E:/EVT/天然地震_EVT");
		write_dir.assign("E:/EVT/tianran_txt123/");
	}

	vector<string> filenames;

	//读取所有的文件，包括子文件的文件  
	//GetAllFiles(read_dir, filenames);  

	//读取所有格式为evt的文件  
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
