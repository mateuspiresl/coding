#include <iostream>
#include "vector.h"

int main()
{
	mystd::vector<float> x;
	x.push_back(10.2f);
	x.push_back(20.3f);
	x.push_back(30.4f);

	for (std::size_t i = 0; i < x.size(); i++)
	{
		x[i] = x[i] * 2;
		std::cout << x[i] << std::endl;
	}

	return 0;
}