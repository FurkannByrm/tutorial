// #include <iostream>

// void f1()
// {
// 	const int x = 10;
// 	auto a = x;
// 	auto &b = x;
// 	decltype(x) c = 0;

// 	++a;//11
// 	++b;//const value
// 	++c;//const value 
// }


// void f2()
// {
// 	int x = 10;
// 	int y = 20;
// 	const int *p = &x;
// 	int *const cp = &x;

// 	auto a = p;
// 	auto b = cp;

// 	a = &y;
// 	*a = 20;
// 	b = &y;
// 	*b = 56;
// }


// void f3()
// {
// 	int x = 10;
// 	int *p = &x;
// 	int **pp = &p;

// 	decltype(p) a;
// 	decltype(*p) b;
// 	decltype(+*p) c;
// 	decltype(pp) d;
// 	decltype(*pp) e;
// 	decltype(**pp) f;
// }

// void f4()
// {
// 	int arr[]{ 1, 2, 3, 4 };
// 	decltype(arr)a;
// 	auto b{ arr };
// 	auto &c{ arr };

// 	++a;
// 	++b;
// 	++c;
// 	++*a;
// 	++*b;
// 	++*c;
// }

// void f5()
// {
// 	auto x = 10;
// 	auto y = &x;
// 	auto z = &y;

// 	y = *z;
// 	x = **z;
// 	y = 0;
// 	z = 0;	
// }

// void f6()
// {
// 	const int x = 10;
// 	const int &r = x;
// 	auto a = r;
// 	decltype(a) b;
// 	++a;
// 	++b;
// 	decltype(*&x) c;
// }