// //int &f1();
// //int f2();

// int work8()
// {
// 	int x = 10;
// 	int y = 35;
// 	const int primes[]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
// 	int a[]{ 1, 2, 4 };
// 	//int &r1; //must be initialize
// 	int &r2(++x);// pre-increment and pre-decrement lvalue expresion in cpp, but that is rvalue expression in c.
// 	//int &r3{ 10 };// must be const, rvalue expression.
// 	const int &r4{ int() };// temporary object 
// 	const int &r5{ int{} };// temporary object 
// 	//int &r6 = +y;
// 	int &r7 = (x, y);
// 	int &r8 = x > 10 ? x : y;
// 	//int &r9 = f1();
// 	//int &r10 = f2();
// 	//int &r11 = primes[5];
// 	int const &r12 = *primes;
// 	const int &r13{ x };
// 	//int *&r14 = a;
// 	int(&r15)[] = a;
// 	int(&r16)[3] = a;
// }