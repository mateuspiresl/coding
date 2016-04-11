#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>

using namespace std;

int main()
{
	bitset<4> bs(8);
	string bss = bs.to_string();
	istringstream iss(bss);

	cout << iss << endl;

	int r = 1;
	iss >> std::setbase(2) >> r;
	cout << r << endl;
	iss >> std::setbase(10) >> r;
	cout << r << endl;

	cout << std::setbase(10) << std::showbase << r << endl;

	return 0;
}