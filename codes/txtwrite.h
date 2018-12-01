#pragma once
#ifndef TXTWRITE_H
#define TXTWRITE_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class TxtWrite
{
public:
	
	TxtWrite(string value);
	TxtWrite(const TxtWrite & txtwrite);

	void write(string content);




	~TxtWrite();

	void setFilename(const string& value);
	string getFilename()const;
private :
	TxtWrite();
	string filename;

};

#endif