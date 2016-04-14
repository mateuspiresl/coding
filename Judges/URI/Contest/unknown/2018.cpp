/*
a primeira linha contém a descrição da prova,
a segunda linha contém o país que ficou campeão nesta modalidade,
a terceira linha contém o país vice-campeão e
a última linha contém o país que ficou com a medalha de bronze na referida prova
*/

#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;

const ull MEDALS[3] = { 100000000, 10000, 1 };

int getMedals(ull all, int i)
{
	if (i == 0)
		return all / MEDALS[i];

	all %= MEDALS[0];

	if (i == 1)
		return all / MEDALS[i];

	return all %= MEDALS[1];
}

int main()
{
	map<string, ull> countries;

	string stage;

	while (getline(cin, stage))
	{
		for (int i = 0; i < 3; i++)
		{
			string country;
			getline(cin, country);

			map<string, ull>::iterator found = countries.find(country);

			if (found != countries.end())
				found->second += MEDALS[i];
			else
				countries.insert(pair<string, ull>(country, MEDALS[i]));
		}
	}

	map<ull, set<string>*, greater<long long> > rank;
	map<string, ull>::iterator it = countries.begin();

	while (it != countries.end())
	{
		map<ull, set<string>*, greater<long long> >::iterator found = rank.find(it->second);

		if (found != rank.end())
			found->second->insert(it->first);
		else
		{
			set<string>* order = new set<string>;
			order->insert(it->first);
			rank.insert(pair<ull, set<string>*>(it->second, order));
		}

		it++;
	}

	map<ull, set<string>*, greater<long long> >::iterator r = rank.begin();

	cout << "Quadro de Medalhas" << endl;

	while (r != rank.end())
	{
		set<string>* order = r->second;
		set<string>::iterator o = order->begin();

		while (o != order->end())
		{
			cout << *o;
			cout << " " << getMedals(r->first, 0);
			cout << " " << getMedals(r->first, 1);
			cout << " " << getMedals(r->first, 2) << endl;

			o++;
		}

		r++;
	}

	return 0;
}