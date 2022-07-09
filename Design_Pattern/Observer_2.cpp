#include<iostream>
#include<vector>
#include<list>
#include<iterator>

using namespace std;

class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void update(int) = 0;
};

class ISubject
{
public:
	virtual ~ISubject() {};
	virtual void subscribe(IObserver*)=0;
	virtual void unsubscribe(IObserver*)=0;
	virtual void notifyAll(int)=0;
};


class Shop :public ISubject
{
	list<IObserver*> CList;
public:
	Shop()
	{}
	void subscribe(IObserver* obs)
	{
		CList.push_back(obs);
	}

	void unsubscribe(IObserver* obs)
	{
		CList.remove(obs);
	}

	void updatePrice(int price)
	{
		notifyAll(price);
	}
	void notifyAll(int price)
	{
		list<IObserver*>::iterator itr = CList.begin();
		while (itr != CList.end())
		{
			(**itr).update(price);
			itr++;
		}
	}
	~Shop() {}
};

class Customer : public IObserver
{
	int price;
public:
	Customer(Shop &obj)
	{
		obj.subscribe(this);
		price = 100;
	}
	~Customer()
	{

	}
	void removeSubscription(Shop &obj)
	{
		obj.unsubscribe(this);
	}
	void update(int cost)
	{
		
		price = cost;
		cout << " price changed to  " << price << endl;
	}
	int getCurrentPrice()
	{
		return price;
	}

};




void clientCode()
{
	Shop* s1 = new Shop();
	Customer* c1 = new Customer(*s1  );
	Customer* c2 = new Customer(*s1);
	Customer* c3 = new Customer(*s1);

	cout << c1->getCurrentPrice() << endl;
	int changedPrice;
	while(cin>>changedPrice,changedPrice!=-1)s1->updatePrice(changedPrice);
	c2->removeSubscription(*s1);
	while (cin >> changedPrice, changedPrice != -1)s1->updatePrice(changedPrice);

}
int main()
{
	clientCode();
	return 0;
}