class Dummy {
public:
	static int x_;
	int y_;
};

//int Dummy::x_ = 1;

int main()
{
	Dummy a;
	Dummy b;
	Dummy c;

	a.x_ = 100;

	a.y_ = 2;
	b.y_ = 3;
	c.y_ = 4;

	return a.y_ + b.y_ + c.y_;
}