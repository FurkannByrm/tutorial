#include <iostream>

int work10() 
{
	int ival = 1;
	const int &r = ival > 0 ? ival : 1;//temporary object(rvalue expression)
	ival = 5;
	std::cout << ival << r;
	return 0;
}