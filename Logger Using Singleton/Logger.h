#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class Logger
{
private:
	static fstream* fw;
	Logger();
	Logger(const Logger& ref);
	Logger& operator=(const Logger& ref);

public:
	static fstream& getLoggerObj();


	
	~Logger();
	
};
