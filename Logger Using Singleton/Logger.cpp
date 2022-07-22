#include"Logger.h"


	Logger::Logger()
	{
		//fw = new fstream();

	};
	Logger::Logger(const Logger& ref) {}
	//Logger& Logger::operator=(const Logger& ref) {}


	fstream& Logger::getLoggerObj()
	{
		if (!fw)
		{
			int Time = (unsigned)time(NULL);
			char logFileName[1024];
			sprintf(logFileName, "C:\\Users\\KISHOR~1.PAT\\AppData\\Local\\Temp\\OC_ISSUE_123\\kpatil_%d", Time);
			//fw->open(logFileName, ios::app);
			fw = new fstream(logFileName, ios::app);
			return *fw;
		}
		return *fw;
	}


	Logger::~Logger()
	{
		(*fw).close();
		delete[]fw;

	}

fstream* Logger::fw = NULL;