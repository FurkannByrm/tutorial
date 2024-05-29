#include <iostream>


int main()
{
    std::cout<<"hello"<<std::endl;

 
    constexpr int x = 3;
    // decltype((x)) r = x;
    constexpr int y = x;
    std::cout<<y<<std::endl;
    return 0;
}















