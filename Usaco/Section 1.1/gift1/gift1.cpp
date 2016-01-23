/*
ID: mateusp1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Person {
	vector<Person*> receivers;
	int initialMoney;
	int money;

	public:
		Person();
		void setMoney(int);
		void addReceiver(Person*);
		void share();
		void receive(int);
		int difference();
};

Person::Person()
{
	initialMoney = 0;
	money = 0;
}

void Person::setMoney(int initial_money)
{
	initialMoney = initial_money;
	money += initial_money;
}

void Person::addReceiver(Person* receiver) {
	receivers.push_back(receiver);
}

void Person::share()
{
	if (receivers.size() == 0)
		return;

	int toShare = initialMoney / receivers.size();
	money -= toShare * receivers.size();

	for (vector<Person*>::iterator it = receivers.begin(); it != receivers.end(); ++it)
		(*it)->receive(toShare);
}

void Person::receive(int given) {
	money += given;
}

int Person::difference() {
	return money - initialMoney;
}

int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	int n;
	fin >> n;

	map<string, Person*> people;
	queue<string> peopleNames;

	for (int i = 0; i < n; i++)
	{
		string name;
		fin >> name;
		Person* person = new Person();

		people.insert(pair<string, Person*>(name, person));
		peopleNames.push(name);
	}

	for (int i = 0; i < n; i++)
	{
		string giver;
		fin >> giver;

		int money, personCount;
		fin >> money >> personCount;

		Person* person = people.find(giver)->second;
		person->setMoney(money);

		while (personCount--)
		{
			string receiver;
			fin >> receiver;

			person->addReceiver(people.find(receiver)->second);
		}

		person->share();
	}

	while ( ! peopleNames.empty())
	{
		string name = peopleNames.front();
		peopleNames.pop();

		fout << name << " " << people.find(name)->second->difference() << "\n";
	}

	return 0;
}
