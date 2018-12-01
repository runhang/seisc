#include "stdafx.h"
#include "MathUtils.h"


MathUtils::MathUtils()
{
}


MathUtils::~MathUtils()
{
}

union MathUtils::int_float_bits {
	int int_bits;
	float float_bits;
};

union MathUtils::longlong_Double_bits {
	long long long_bits;
	double double_bits;
};


short MathUtils::toShort(char * value){

	int short ch1 = value[1];
	unsigned short ch2 = value[0];
	//if ((ch1 | ch2) < 0)
		//return;
	ch1 = ch1 << 8;
	ch2 = (ch2 & 255);
	//ch2 = ch2 << 8;
	//ch2 = ch2 >> 8;
	return (short)(ch1 + ch2);
}

int MathUtils::toInt(char * value) {
	int ch1 = value[3];
	unsigned int ch2 = value[2];
	unsigned int ch3 = value[1];
	unsigned int ch4 = value[0];

	ch1 = ch1 << 24;

	ch2 = ch2 << 24;
	ch2 = ch2 >> 8;

	ch3 = ch3 << 24;
	ch3 = ch3 >> 16; 

	ch4 = ch4 << 24;
	ch4 = ch4 >> 24;
	int ch = ch1 + ch2 + ch3 + ch4;
	return ch;
}

unsigned long long MathUtils::toLong(char * value){
	long long ch8 = value[7];
	unsigned long long ch7 = value[6];
	unsigned long long ch6 = value[5];
	unsigned long long ch5 = value[4];
	unsigned long long ch4 = value[3];
	unsigned long long ch3 = value[2];
	unsigned long long ch2 = value[1];
	unsigned long long ch1 = value[0];

	ch1 = (ch1 & 255) << 0;

	ch2 = (ch2 & 255) << 8;

	ch3 = (ch3 & 255) << 16;

	ch4 = (ch4 & 255) << 24;

	ch5 = (ch5 & 255) << 32;

	ch6 = (ch6 & 255) << 40;

	ch7 = (ch7 & 255) << 48;

	ch8 = (ch8 & 255) << 56;

	long long  ch = ch1 + ch2 + ch3 + ch4 + ch5 + ch6 + ch7 + ch8;
	return ch;
	/*
	return (((long long)value[7] << 56) +
		((long long)(value[6] & 255) << 48) +
		((long long)(value[5] & 255) << 40) +
		((long long)(value[4] & 255) << 32) +
		((long)(value[3] & 255) << 24) +
		((value[2] & 255) << 16) +
		((value[1] & 255) << 8) +
		((value[0] & 255) << 0));*/
}

float MathUtils::toFloat(char * in) {
	int value = toInt(in);
	return intToFloat(value);
}

double MathUtils::toDouble(char * in) {
	unsigned long long value = toLong(in);
	return longlongToDouble(value);
}


float MathUtils::intToFloat(int& value){
	union int_float_bits bits;
	bits.int_bits = value;
	return bits.float_bits;
}

double MathUtils::longlongToDouble(long long value) {
	
	union longlong_Double_bits bits;
	bits.long_bits = value;
	return bits.double_bits;
	
	//double ull = (value << 53) - 1;
	//return ull;
	/*
	int e = (int)((value >> 52) & 0x7ffL);
	long m = (e == 0) ?
		(value & 0xfffffffffffffL) << 1 :
		(value & 0xfffffffffffffL) | 0x10000000000000L;
	return m;
	*/
};



