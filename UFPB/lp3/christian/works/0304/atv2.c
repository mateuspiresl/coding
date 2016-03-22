struct Bottle {
	char brandLetter;
	int liters;
};

struct Bottle fillBottle(struct Bottle b, int liters)
{
	b.liters += liters;
	return b;
}

int main()
{
	struct Bottle b;
	b.brandLetter = 'C';
	b.liters = 0;

	b = fillBottle(b, 12);

	return 0;
}