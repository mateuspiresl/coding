/*
ID: mateusp1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

string nameToNumber(string);

int main()
{
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream dictIn("dict.txt");
	
	map<string, vector<string>*> dict;

	while ( ! dictIn.eof())
	{
		string name;
		dictIn >> name;

		if (name.length() == 0)
			continue;

		string number = nameToNumber(name);
		map<string, vector<string>*>::iterator entry = dict.find(number);

		if (entry != dict.end())
			entry->second->push_back(name);
		else
		{
			vector<string>* names = new vector<string>;
			names->push_back(name);
			dict.insert(pair<string, vector<string>*>(number, names));
		}
	}

	string number;
	fin >> number;

	map<string, vector<string>*>::iterator entry = dict.find(number);

	if (entry != dict.end())
	{
		vector<string>* names = entry->second;
		sort(names->begin(), names->end());

		for (std::vector<string>::iterator it = names->begin(); it != names->end(); it++)
			fout << *it << "\n";
	}
	else fout << "NONE\n";

	return 0;
}

string nameToNumber(string name)
{
	string number = name;

	for (int i = 0; i < name.length(); i++)
	{
		switch (name[i])
		{
			case 'A':
			case 'B':
			case 'C':	number[i] = '2';
						break;
			case 'D':
			case 'E':
			case 'F':	number[i] = '3';
						break;
			case 'G':
			case 'H':
			case 'I':	number[i] = '4';
						break;
			case 'J':
			case 'K':
			case 'L':	number[i] = '5';
						break;
			case 'M':
			case 'N':
			case 'O':	number[i] = '6';
						break;
			case 'P':
			case 'R':
			case 'S':	number[i] = '7';
						break;
			case 'T':
			case 'U':
			case 'V':	number[i] = '8';
						break;
			case 'W':
			case 'X':
			case 'Y':	number[i] = '9';
		}
	}

	return number;
}