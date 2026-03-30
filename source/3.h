#ifndef CLASS_B_H  
#define CLASS_B_H  

#include "2.h"  
#include <iostream>
class B
{
public:
    void InvokeA();
    B(){}
    void Print()
    {
        std::cout << "This is class B\n";
    }
};

#endif 