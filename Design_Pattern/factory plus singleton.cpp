#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

mutex mtx;

enum DBS{SQL,ORACLE};

class DBConnect
{
public:
	virtual void connectDB() = 0;
};
class SQL_DB:public DBConnect
{
private:
	static SQL_DB* ptr;

	SQL_DB() {  };
	SQL_DB(const SQL_DB& ref) = delete;
	SQL_DB& operator=(const SQL_DB& ref) = delete;
public:


	static SQL_DB* getInstance()
	//SQL_DB* getInstance()
	{
		unique_lock<mutex>lock(mtx);
		if (ptr)
			return ptr;
		else
		{
			ptr = new SQL_DB();
			return ptr;
		}
		lock.unlock();
	}


	void connectDB()
	{
		cout << "connected  to SQL_DB --- " << endl << endl;;
	}
};
SQL_DB* SQL_DB::ptr = NULL;

class ORACLE_DB :public DBConnect
{
private:
	static ORACLE_DB* ptr;

	ORACLE_DB() {  };
	ORACLE_DB(const ORACLE_DB& ref) = delete;
	ORACLE_DB& operator=(const ORACLE_DB& ref) = delete;
public:


	static ORACLE_DB* getInstance()
	{
		unique_lock<mutex>lock(mtx);
		if (ptr)
			return ptr;
		else
		{
			ptr = new ORACLE_DB();
			return ptr;
		}
		lock.unlock();
	}


	void connectDB()
	{
		cout << "connected  to ORACLE_DB DB--- " << endl << endl;;
	}
};
ORACLE_DB* ORACLE_DB::ptr = NULL;



class DBFactory
{
public:
	static DBConnect* getDBInstance(DBS db)
	{
		if (db == SQL)
		{
			return SQL_DB::getInstance();
		}
		else if (db == ORACLE)
		{
			return ORACLE_DB::getInstance();
		}
		else
			return NULL;
	}
};

int main()
{
	DBConnect *db1 = DBFactory::getDBInstance(SQL);
	db1->connectDB();
	DBConnect* db2 = DBFactory::getDBInstance(SQL);
	(*db2).connectDB();

}


