int x[5] = { 1, 2, 3, 4, 5 };

int Sum() {
	int i;
	int acc = 0;

	for (i = 0; i < 5; i++)
		acc += x[i];

	return acc;
}

int main() {
	int sum_value = Sum();

	return sum_value;
}
