#if 0
#include"1.h"
#include"4.h"
#include<iostream>
#include<vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <climits>
template <typename T>
class Base {
public:
    void func(T& container) {
        m_it = container.begin();
    }
private:
    decltype(T().begin()) m_it;  //注意这里
};

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
    return t + u;
}

void vir_fun() {
}
template <typename T, typename... args>
void vir_fun(T argc, args... argv)
{
    std::cout << argc << std::endl;
    //开始递归，将第一个参数外的 argv 参数包重新传递给 vir_fun
    vir_fun(argv...);
}

class Foo
{
public:
    Foo(int){}
private:
    Foo(const Foo&);
};

int main()
{
    //std::cout << "mian函数输出:" << std::endl;
    //std::cout<< "调用2，3项目" << std::endl;
    //print1(5);
    //std::cout << "调用4，5项目" << std::endl;
    //print12(4);
    /*std::string str;
    foo(str);
    printf("%s\n", str.c_str());
    return 0;
    int a;
    std::cin >> a;*/
    //const std::vector<int> v;
    //Base<const std::vector<int>> obj;
    ////Base<int> obj;
    //obj.func(v);
    //std::cout << add(1, 2) << std::endl;
    //vir_fun(1, -2.5, "a", "fhoiahf");
    //auto bar = std::make_tuple(1, 2.0, 3.0);
    //int a;;
    //float b;
    //double c;
    //std::tie(a, b, c) = bar;

    //Foo a1(123);
    //Foo a2 = 123;  //error: 'Foo::Foo(const Foo &)' is private
    //Foo a3 = { 123 };
    //Foo a4{ 123 };
    //int a5 = { 3 };
    //int a6{ 3 };

    //int num[4] = { 4, 2, 3, 1 };
    ////对 a 数组中的元素进行排序
    //std::sort(num, num + 4, [=](const int &x, const int& y) ->bool { return x < y; });
    //for (int n : num) {
    //    std::cout << n << " ";
    //}

    /*auto except1 = []()noexcept {
        throw 100;  //没有异常,不应该抛出
        };
    auto except2 = []()throw(char) {
        throw 10;
        }; //抛出字符不应该抛出整型
    try {
        except1();
        except2();
    }
    catch (int) {
        std::cout << "捕获到了整形异常" << std::endl;
    }*/
   /* std::cout << "long long最大值：" << LLONG_MIN << " " << LLONG_MIN << "\n";
    std::cout << "long long最小值：" << LLONG_MAX << " " << LLONG_MAX << "\n";
    std::cout << "unsigned long long最大值：" << ULLONG_MAX << " " <<  ULLONG_MAX;*/

    /*const int a = 10;
    const int* p = &a;*/
    //*p = 20;                  //compile error
    //int b = const_cast<int>(a);

    //const int a = 10;

    //const int* p = &a;

    //int* q;

    //q = const_cast<int*>(p);

    //*q = 20;    //fine
    //std::cout << a << " " << *p << " " << *q << std::endl;

    //std::cout << &a << " " << p << " " << q << std::endl;
    return 0;
}
#endif