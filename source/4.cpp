#include"4.h"
#include"5.h"
#include<iostream>
using namespace std;
void print4(int a)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "4ÏîÄ¿Êä³ö" << i << std::endl;
        print5(i*a);
    }
}
void foo(string& str)
{
    str = "hello";
}