int main() {
	char x[4];
	int *px;
	px = (int*) x;

	x[0] = 'A';
	x[1] = 'B';
	x[2] = 'C';
	x[3] = 'D';

	*px = 1;

	return 0;
}