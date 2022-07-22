#include"Person.h"

	Person::Person()
	{
		fstream &fl = Logger::getLoggerObj();
		fl << "Person Constructor callled \n";
	}
