#ifndef CLASS_B_H  
#define CLASS_B_H  

#include "2.h"  
#include <iostream>
class A;
class B
{
public:
    void InvokeA()
    {
        A* a;
        //a->Print();
    }
    B(){}
    void Print()
    {
        std::cout << "This is class B\n";
    }
};

#endif 