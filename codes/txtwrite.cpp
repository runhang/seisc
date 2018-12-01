#include "stdafx.h"
#include "txtwrite.h"


TxtWrite::TxtWrite(){

}

TxtWrite::TxtWrite(string value) {
	filename = value;
}

TxtWrite::TxtWrite(const TxtWrite & txtwrite) {
	filename = txtwrite.filename;
}

TxtWrite::~TxtWrite(){

}

void TxtWrite::write(string content){
	ofstream ofs(filename.c_str(), ios::out | ios::app);
	//cout << filename.c_str() << endl;
	ofs.write(content.c_str(), content.length());
	//cout << content.c_str();
	ofs.flush();
	ofs.close();
}

void TxtWrite::setFilename(const string & value) {
	filename = filename;
}

string TxtWrite::getFilename() const {
	return filename;
}
