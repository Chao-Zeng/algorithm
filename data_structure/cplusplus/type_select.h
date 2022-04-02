#pragma once

// template<typename T1, typename T2, typename T3, typename T4>
// struct select<0,T1,T2,T3,T4> { using type = T1; }; // specialize for N==0

// template<typename T1, typename T2, typename T3, typename T4>
// struct select<1,T1,T2,T3,T4> : select<0, T2, T3, T4>
// {}; // specialize for N==1

// template<typename T1, typename T2, typename T3, typename T4>
// struct select<2,T1,T2,T3,T4> : select<1, T2, T3, T4>
// {}; // specialize for N==2

// template<typename T1, typename T2, typename T3, typename T4>
// struct select<3,T1,T2,T3,T4> : select<2, T2, T3, T4>
// {}; // specialize for N==3


template<int N, typename... Types>
struct select{};

template<int N, typename T, typename... Types>
struct select<N, T, Types...> : select<N-1, Types...> {};

template<typename T, typename... Types>
struct select<0, T, Types...>
{
    using type = T;
};
