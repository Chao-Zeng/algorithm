#pragma once

#include <type_traits>
#include <iostream>


template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
enable_via_return_type(T t)
{
    std::cout << "enable via return type, T is integer " << t << std::endl;
    return t;
}

template<typename T>
void enable_via_parameter(T t, std::enable_if_t<std::is_floating_point_v<T>>* = 0)
{
    std::cout << "enable via parameter, T is float " << t << std::endl;
}

// 不要使用非类型模板参数来做重载，有些ABI(Itanium)会生成相同的函数签名，导致链接错误的函数
template<typename T,
         typename std::enable_if<std::is_integral_v<T>, int>::type = 0>
void enable_via_func_non_type_template_param(T t)
{
    std::cout << "enable via func non-type template parameter, T is " << t << std::endl;
}

// 类型模板参数只能用来检查参数，不能用来重载
// default template arguments are not accounted for in function template equivalence
template<typename T,
         typename = typename std::enable_if_t<std::is_integral_v<T>>
        >
void enable_via_func_type_template_param(T t)
{
    std::cout << "enabled via func type template parameter, T is " << t << std::endl;
}

class A
{
public:
    A() { std::cout << __FUNCTION__ << "\n"; }
    ~A() { std::cout << __FUNCTION__ << "\n"; }
    int func(int) { return 0;}
};

template<typename T,
         typename = typename std::enable_if_t<std::is_same_v<T, A>>
        >
class B
{
public:
    B() { std::cout << __FUNCTION__ << "\n"; }
    ~B() { std::cout << __FUNCTION__ << "\n"; }

private:
    T t;
};

class C {};
