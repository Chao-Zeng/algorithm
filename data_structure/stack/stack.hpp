#pragma once

#include <cstring>
#include <memory>
#include <ostream>

template <typename value_type>
class stack
{
public:
    stack(size_t size)
        : s_(new value_type[size]), capacity_(size)
    {
    }

    stack() : stack(1)
    {
    }

    ~stack() = default;

    void push(value_type value)
    {
        if (capacity_ - 1 == top_)
        {
            increase_capacity();
        }
        
        s_[++top_] = value;
    }

    value_type pop()
    {
        return s_[top_--];
    }

    value_type top() const
    {
        return s_[top_];
    }

    bool empty()
    {
        return top_ == -1 ? true : false;
    }

    size_t size() const
    {
        return top_ + 1;
    }

    template<typename T>
    friend std::ostream & operator <<(std::ostream &out, const stack<T> & s);

private:
    void increase_capacity()
    {
        std::unique_ptr<value_type[]> a(new value_type[2*capacity_]);
        memcpy(a.get(), s_.get(), sizeof(value_type)*capacity_);
        s_.swap(a);
        capacity_ *= 2;
    }

private:
    std::unique_ptr<value_type[]> s_;
    int top_ {-1};
    size_t capacity_;
};

template<typename T>
inline std::ostream & operator <<(std::ostream &out, const stack<T> & s) 
{
    int index = 0;
    while (index <= s.top_)
    {
        out << s.s_[index] << " ";
        index++;
    }

    return out;
}
