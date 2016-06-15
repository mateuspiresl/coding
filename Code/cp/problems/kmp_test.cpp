#include "../alg_string.cpp"

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int* occurr = kmp_process(b);
	for (int i = 0; i <= b.length(); i++)
		cout << occurr[i] << " ";
	cout << endl;

	vector<int> positions;
	kmp_get(a, b, positions);
	for (int i = 0; i < positions.size(); i++)
		cout << a.substr(positions[i], b.length()) << endl;

	cout << kmp_count(a, b) << endl;
	cout << kmp_contains(a, b) << endl;

	return 0;
}