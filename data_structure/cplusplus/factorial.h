#pragma once


template<int N>
int factorial()
{
    return N * factorial<N-1>();
}

template<>
int factorial<1>()
{
    return 1;
}

template<int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<1> {
    static const int value = 1;
};
