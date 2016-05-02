#include <iostream>

using namespace std;

int main()
{
	int ntc;
	cin >> ntc;

	for (int tc = 1; tc <= ntc; tc++)
	{
		vector< pair<string, string> > v;
		map<string, vector<int>* > fm;
		map<string, vector<int>* > sm;

		map<string, int>::iterator fi, si;

		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			string f, s; cin >> f >> s;
			v.insert(pair<string, string>(f, s));

			fi = fm.find(f);
			si = sm.find(s);

			if (fi != fm.end())
				fi->second->insert(i);
			
			if (si != sm.end())
				si->second->insert(i);
		}

		vector< pair<string, string> >::iterator vi;
		set<int> valid;

		for (fi = fm.begin(); fi != fm.end(); fi++)
		{
			if (fi->second->size() == 1)
			{
				for (vi = fi->second->begin(); vi != fi->second->end(); vi++)
					valid.insert(vi->second);
			}
			else
			{
				for (vi = fi->second->begin(); vi != fi->second->end(); vi++)
				{
					si = sm.find(vi->second);

					if (si->second->size() == 1)
						valid.insert(si->second->begin());
					else
					{
						
					}
				}
			}
		}


		cout << "Case #" << tc << ": " << endl;
	}

	return 0;
}