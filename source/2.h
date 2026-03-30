#ifndef CLASS_A_H  
#define CLASS_A_H  

#include "3.h"  
#include <iostream>
class A
{
public:
    A(){}
    void InvokeB();

    void Print()
    {
        std::cout << "This is class A\n";
    }
};

#endif  