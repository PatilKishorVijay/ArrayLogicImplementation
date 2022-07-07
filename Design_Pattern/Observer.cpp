#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<iterator>
#include<algorithm>
#include<mutex>

using namespace std;


class shop
{
	string name;
	float price;

public:
	shop(string str)
	{
		name = str;
		price = 100;
	}

	void newUpdateInfo(float price)
	{
		this->price = price;
		cout << "new price  at " << name << " is " << price << endl;
	}
	void  getCurrentPrice()
	{
		cout << "current price at " << name << " is " << price << endl << endl;;
	}
};

class shopOperation
{
	vector<shop*>list;
	vector<shop*>::iterator itr;
public:
	void subscribeInfo(shop* shop)
	{
		list.push_back(shop);
	}
	void unsubscribeInfo(shop* shop)
	{
		list.erase(std::remove(list.begin(), list.end(), shop), list.end());
	}

	void notifyAll(float price)
	{
		for (auto itr : list)
		{
			itr->newUpdateInfo(price);
		}
	}
};

class updateProductInfo :public shopOperation
{
public:
	void updateInfo(float price)

	{
		notifyAll(price);
	}
};
int main()
{
	shop s1("shop 1");
	shop s2("shop 2");
	updateProductInfo product;

	product.subscribeInfo(&s1);
	product.subscribeInfo(&s2);
	s1.getCurrentPrice();
	product.updateInfo(105);
	product.unsubscribeInfo(&s1);

	product.updateInfo(111);

}
