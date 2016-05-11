int main()
{
	int i = 10;
	int * const ri = &i;

	return *ri;
}