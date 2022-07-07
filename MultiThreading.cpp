#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
#include<condition_variable>
using namespace std;

int i = 0;
int MAX = 20;
mutex mtx;
condition_variable cond;
static int EvenSum, oddSum;
void printOdd()
{
	while (i <= MAX) {
		unique_lock<mutex> lock(mtx);
		//while (i % 2 != 0) cond.wait(lock);
		if (i % 2 != 0)
		{
			//cout << i << endl;
			oddSum += i++;
		}
		else
			cond.wait(lock);
		this_thread::sleep_for(chrono::seconds(1));
		lock.unlock();
		cond.notify_one();
	}


}

void printEven()
{
	while (i <= MAX) {
		unique_lock<mutex> lock(mtx);
		//while (i % 2 == 0) cond.wait(lock);
		if (i % 2 == 0)
		{
			//cout << i << endl;
			EvenSum += i++;
		}
		else
			cond.wait(lock);
		this_thread::sleep_for(chrono::seconds(1));
		lock.unlock();
		cond.notify_one();
	}



}



int main()
{
	thread t1(printOdd);
	thread t2(printEven);
	t1.join();
	t2.join();

	cout << EvenSum << endl;
	cout << oddSum << endl;
}