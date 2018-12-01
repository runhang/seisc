#pragma once
#ifndef MATHUILS_H
#define MATHUILS_H


class MathUtils
{
public:

	MathUtils();
	~MathUtils();

	union int_float_bits;
	union longlong_Double_bits;

	static short toShort(char * value);
	static int toInt(char * value);
	static unsigned long long toLong(char * value);
	static float intToFloat(int & value);
	static double longlongToDouble(long long value);
	static float toFloat(char * in);
	static double toDouble(char * in);
};

#endif