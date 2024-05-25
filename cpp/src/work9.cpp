#include <iostream>

int foo(int &x, int &y) 
{
	x = 3;
	y = 4;
	return x + y;
}

int work9() 
{
	int x = 1;
	int y = 2;
	int z = foo(x, x);

	std::cout<< "x = " << x <<" y = "<< y <<" z = "<< z;
	return 0;
}
