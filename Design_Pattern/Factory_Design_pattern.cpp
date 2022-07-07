#include<iostream>

using namespace std;

enum TataProducts { Nexon_, Nano_ };

class TataMotors
{
public:
	virtual void printVehicle() = 0;
};

class Nexon :public TataMotors
{
public:
	void printVehicle()
	{
		cout << "nexon " << endl;
	}
};

class Nano : public TataMotors
{
public:
	void printVehicle()
	{
		cout << "nano " << endl;
	}
};

class Factory
{
public:
	static TataMotors* getVehicle(TataProducts TP)
	{
		if (TP == Nexon_)
			return new Nexon();
		else if (TP == Nano_)
			return new Nano();
		else
			return NULL;
	}
};


int main()
{
	TataMotors* v = Factory::getVehicle(Nexon_);
	v->printVehicle();

}