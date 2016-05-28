#include <iostream>

using namespace std;

template <class T>
class SmartPtr {
	
public:
	SmartPtr(T* ptr = nullptr) :
		ptr_(ptr)
	{ }

	~SmartPtr() {
		delete ptr_;
	}

private:
	T* ptr_ = nullptr;

};

class Test {

public:
	~Test() {
		cout << "apagado" << endl;
	}

};

int main()
{
	Test* x = new Test;

	SmartPtr<Test> sptr(x);

	return 0;
}