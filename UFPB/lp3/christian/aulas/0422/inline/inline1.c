int F1(int a)
{
	return a + 1;
}

int main(int argc, char *argv[])
{
	int x;

	if (argc > 1)
		x = 2;
	else
		x = 1;

	x = F1(x);

	return x;
}