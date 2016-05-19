class CPPClass {
public:
	int x_, y_;

	void set(int a, int b) {
		this->x_ = a;
		this->y_ = b;
	}

	int getX() {
		return this->x_;
	}
};

CPPClass cppobj;

int main()
{
	cppobj.set(10, 20);
	return cppobj.getX();
}