#include <iostream>

using namespace std;

class Cl {
private:
	static Cl* instance;

	Cl(int v) { a = v; }
	Cl(const Cl& copy) { }
	
public:
	int a = 10;

	static Cl& single() {
		if (Cl::instance == nullptr)
			Cl::instance = new Cl(20);

		return *instance;
	}
};

Cl* Cl::instance = nullptr;

void print(Cl copy) {
	cout << copy.a << endl;
}

int main()
{
	Cl& cl = Cl::single();
	cout << cl.a << endl;
	cl.a = 11;
	cout << cl.a << endl;
	Cl& cl2 = Cl::single();
	cout << cl2.a << endl;

	print(cl2);

	return 0;
}