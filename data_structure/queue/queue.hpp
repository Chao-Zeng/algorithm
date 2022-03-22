#pragma once

#include <memory>

template <typename T>
class queue
{
public:
    queue(size_t capacity = 10)
      : q_(new T[capacity]), capacity_(capacity),
        head_(0), tail_(0)
    {
    }

    void enqueue(T val)
    {
        q_[tail_] = val;

        if (tail_ == capacity_ - 1)
        {
            tail_ = 0;
        }
        else
        {
            tail_ += 1;
        }
    }

    T dequeue()
    {
        T val = q_[head_];
        if (head_ == capacity_ - 1)
        {
            head_ = 0;
        }
        else
        {
            head_ += 1;
        }

        return val;
    }

    bool empty()
    {
        return head_ == tail_;
    }

    size_t size()
    {
        if (tail_ > head_)
        {
            return tail_ - head_;
        }
        else
        {
            return capacity_ - (head_ - tail_);
        }
    }

private:
    bool full()
    {
        if (tail_ == capacity_ -1)
        {
            return head_ == 0;
        }

        return tail_ + 1 == head_;
    }

private:
    std::unique_ptr<T[]> q_;
    int head_;
    int tail_;
    size_t capacity_;
};