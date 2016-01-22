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
	vector<Person> receivers;
	int initialMoney;
	int money;

	public:
		//Person();
		void setMoney(int);
		void addReceiver(Person);
		void share();
		void receive(int);
		int difference();
};

void Person::setMoney(int initial_money) {
	initialMoney = initial_money;
	money = initial_money;
}

void Person::addReceiver(Person receiver) {
	receivers.push_back(receiver);
}

void Person::share()
{
	int toShare = initialMoney / receivers.size();
	money -= toShare * receivers.size();

	for (vector<Person>::iterator it = receivers.begin(); it != receivers.end(); ++it)
		it->receive(toShare);
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

	map<string, Person> people;
	queue<Person> row;

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		Person person;

		people.insert(pair<string, Person>(name, person));
		row.push(person);
	}

	for (int i = 0; i < n; i++)
	{
		string giver;
		cin >> giver;

		Person person = people.find(giver)->second;

		int money, personCount;
		cin >> money >> personCount;

		person.setMoney(money);

		while (personCount--)
		{
			string receiver;
			cin >> receiver;

			person.addReceiver(people.find(receiver)->second);
		}

		person.share();
	}

	while (n--)
	{
		fout << row.front().difference() << "\n";
		row.pop();
	}

	return 0;
}
