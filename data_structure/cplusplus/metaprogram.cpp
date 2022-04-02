#include <type_traits>
#include <iostream>

#include "type_select.h"
#include "factorial.h"


void test_select()
{
    std::cout << "std::is_same<select<0, int, float, char, double>::type, int>::value is ";
    std::cout << std::is_same<select<0, int, float, char, double>::type, int>::value << std::endl;
    
    std::cout << "std::is_same<select<1, int, float, char, double>::type, float>::value is ";
    std::cout << std::is_same<select<1, int, float, char, double>::type, float>::value << std::endl;

    std::cout << "std::is_same<select<3, int, float, char, double>::type, double>::value is ";
    std::cout << std::is_same<select<3, int, float, char, double>::type, double>::value << std::endl;

    std::cout << "std::is_same<select<0, int, float, char, double>::type, float>::value is ";
    std::cout << std::is_same<select<0, int, float, char, double>::type, float>::value << std::endl;

    std::cout << "std::is_same<select<1, int, float, char, double>::type, char>::value is ";
    std::cout << std::is_same<select<1, int, float, char, double>::type, char>::value << std::endl;

    std::cout << "std::is_same<select<3, int, float, char, double>::type, int>::value is ";
    std::cout << std::is_same<select<3, int, float, char, double>::type, int>::value << std::endl;
}

void test_factorial()
{
    std::cout << "factorial<5>()=" << factorial<5>() << std::endl;
    std::cout << "Factorial<5>::value=" << Factorial<5>::value << std::endl;
}

int main()
{
    //test_select();
    test_factorial();

    return 0;
}

