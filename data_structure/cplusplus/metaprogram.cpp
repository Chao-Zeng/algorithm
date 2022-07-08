#include <type_traits>
#include <iostream>
#include <cstdio>

#include "type_select.h"
#include "factorial.h"
#include "enable_if.h"

#define LOG(...) std::cout << #__VA_ARGS__ << " is " << __VA_ARGS__ << "\n"

DEFINE_HAS_METHOD(Foo)

void test_select()
{
    LOG(std::is_same<select<0, int, float, char, double>::type, int>::value);
    LOG(std::is_same<select<1, int, float, char, double>::type, float>::value);
    LOG(std::is_same<select<3, int, float, char, double>::type, double>::value);
    LOG(std::is_same<select<0, int, float, char, double>::type, float>::value);
    LOG(std::is_same<select<1, int, float, char, double>::type, char>::value);
    LOG(std::is_same<select<3, int, float, char, double>::type, int>::value);
}

void test_factorial()
{
    LOG(factorial<5>());
    LOG(Factorial<5>::value);
}

void test_enable_if()
{
    enable_via_return_type(1);
    enable_via_parameter(1.0);
    // error for non float type
    //enable_via_parameter(1);
    enable_via_func_non_type_template_param(1);
    enable_via_func_type_template_param(1);

    B<A> b;
    //error
    //B<C> b1;

    if (has_Foo<D, int, int, const char*, const std::string&>::value)
    {
        std::cout << "D have method int Foo(int, const char*, const std::string&);\n";
    }
    else
    {
        std::cout << "D DON'T have method int Foo(int, const char*, const std::string&);\n";
    }

    if (has_Foo<D, void, int, const char*, const std::string&>::value)
    {
        std::cout << "D have method void Foo(int, const char*, const std::string&);\n";
    }
    else
    {
        std::cout << "D DON'T have method void Foo(int, const char*, const std::string&);\n";
    }

    if (has_Foo<D, int, int, const char*>::value)
    {
        std::cout << "D have method int Foo(int, const char*);\n";
    }
    else
    {
        std::cout << "D DON'T have method int Foo(int, const char*);\n";
    }
}

int main()
{
    test_select();
    test_factorial();
    test_enable_if();

    return 0;
}
