#include<iostream>
#include<string>
#include<fstream>
#include"Logger.h"
#include "Person.h"
using namespace std;

//class Logger
//{
//private:
//	static fstream* fw;
//	Logger() 
//	{
//		//fw = new fstream();
//
//	};
//	Logger(const Logger &ref) {}
//	Logger& operator=(const Logger &ref) {}
//	
//public:
//	static fstream& getLoggerObj()
//	{
//		if (!fw)
//		{
//			int Time = (unsigned)time(NULL);
//			char logFileName[1024];
//			sprintf(logFileName, "C:\\Users\\KISHOR~1.PAT\\AppData\\Local\\Temp\\OC_ISSUE_123\\kpatil_%d", Time);
//			//fw->open(logFileName, ios::app);
//			fw = new fstream(logFileName,ios::app);
//			return *fw;
//		}
//		return *fw;
//	}
//
//	void writeToFile()
//	{
//
//	}
//	~Logger()
//	{
//		(*fw).close();
//		delete[]fw;
//
//	}
//};
//fstream* Logger::fw = NULL;
int main()
{
	fstream &logger= Logger::getLoggerObj();
	logger << "kishor\n";
	//logger.close();
	cout << endl;
	fstream& logger2 = Logger::getLoggerObj();
	//logger2.open();
	logger2 << "patil\n";
	Person p;
	//logger2.close();

	//fw->write("kishor\n");
	
}