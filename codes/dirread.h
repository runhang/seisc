#pragma once
#ifndef DIRREAD_H
#define DIRREAD_H

#include <io.h>  
#include <fstream>  
#include <string>  
#include <vector>  
#include <iostream> 


using namespace std;

class DirRead
{
public:
	DirRead();
	~DirRead();

	static void GetAllFiles(string path, vector<string>& files);

	static void GetAllFormatFiles(string path, vector<string>& files, string format);
};

#endif