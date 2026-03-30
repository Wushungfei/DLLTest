#ifndef CLASS_A_H  
#define CLASS_A_H  

#include "3.h"  

class A
{
public:
    A(){}
    void InvokeB()
    {
        B* b;
        b->Print();
    }

    void Print()
    {
        std::cout << "This is class A\n";
    }
};

#endif  