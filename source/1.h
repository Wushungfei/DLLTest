#pragma once
#include<iostream>
//#include"2.h"
//#include"3.h"
#include"4.h"
void print1(int a)
{
    for (int i = 1; i < 4; i++)
    {
        //print2(i*a);
        //print3(i*2*a);
    }
}
void print12(int a)
{
    for (int i = 1; i < 4; i++)
    {
        std::cout << "ÏÈ²»ÓÃ" << std::endl;
        print4(i*i * a);
    }
}
