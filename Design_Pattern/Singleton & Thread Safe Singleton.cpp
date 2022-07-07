#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

mutex mtx;

//class Singleton
//{
//private:
//	static Singleton* ptr;
//	Singleton() { ptr = NULL; };
//	Singleton(const Singleton& ref) = delete;
//	Singleton& operator=(const Singleton &ref)=delete;
//public:
//	static Singleton* getInstance()
//	{
//		if (ptr)
//			return ptr;
//		else
//		{
//			ptr = new Singleton();
//			return ptr;
//		}
//
//	}
//
//	void display()
//	{
//		cout << "display of singleton class" << endl;
//	}
//};
//
////Singleton* Singleton::ptr = NULL;
//int main()
//{
//	Singleton* ptr = Singleton::getInstance();
//	ptr->display();
//
//}


class Singleton
{
private:
	static Singleton* ptr;
	string value;
	Singleton(string str) { value = str; };
	Singleton(const Singleton& ref) = delete;
	Singleton& operator=(const Singleton &ref)=delete;
public:

	
	static Singleton* getInstance(string str)
	{
		unique_lock<mutex>lock(mtx);
		if (ptr)
			return ptr;
		else
		{
			ptr = new Singleton(str);
			return ptr;
		}
		lock.unlock();
	}
	

	void display()
	{
		cout << "display of singleton class--- " << value << endl << endl;;
	}
};
Singleton* Singleton::ptr = NULL;


void foo()
{
	this_thread::sleep_for(chrono::seconds(2));
	Singleton* ptr = Singleton::getInstance("foo");
	ptr->display();
}

void bar()
{
	this_thread::sleep_for(chrono::seconds(2));
	Singleton* ptr = Singleton::getInstance("bar");
	ptr->display();
}

void test()
{
	this_thread::sleep_for(chrono::seconds(2));
	Singleton* ptr = Singleton::getInstance("test");
	ptr->display();
}
int main()
{
	thread t1(foo);
	thread t2(bar);
	thread t3(test);
	t1.join();
	t2.join();
	t3.join();
}


