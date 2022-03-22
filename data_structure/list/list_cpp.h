#pragma once

#include <memory>
#include <stdio.h>
#include <iostream>

template <typename value_type>
struct node{
    value_type value;
    node<value_type> *pre, *next;
};

template <typename value_type>
class list{
public:
    list()
    : size_(0) {
        head_ = new node<value_type>;
        head_->pre = head_;
        head_->next = head_;
    }

    ~list() {
        clean();
        delete head_;
    }

    bool empty() {
        return head_->next == head_ && head_->pre == head_;
    }

    size_t size() {
        return size_;
    }

    size_t size() const {
        return size_;
    }

    void push_back(const value_type& value) {
        node<value_type> *new_node = new node<value_type>;
        new_node->value = value;
        node<value_type> *tail = head_->pre;
        new_node->next = head_;
        new_node->pre = tail;
        tail->next = new_node;
        head_->pre = new_node;

        ++size_;
    }

    void push_front(const value_type& value) {
        node<value_type> *new_node = new node<value_type>;
        new_node->value = value;
        node<value_type> *first = head_->next;
        new_node->next = first;
        new_node->pre = head_;
        first->pre = new_node;
        head_->next = new_node;

        ++size_;
    }

    void pop_back() {
        if (empty())
        {
            return;
        }

        node<value_type> *tail = head_->pre;
        head_->pre = tail->pre;
        tail->pre->next = head_;
        delete tail;
        --size_;
    }

    void pop_front() {
        if (empty()){
            return;
        }

        node<value_type> *front = head_->next;
        head_->next = front->next;
        front->next->pre = head_;
        delete front;
        --size_;
    }

    value_type& front() {
        return head_->next->value;
    }

    value_type& back() {
        return head_->pre->value;
    }

    void clean() {
        size_t count = size_;
        for (size_t i = 0; i < count; ++i)
        {
            pop_back();            
        }        
    }

    node<value_type>* head() {
        return head_;
    }

    node<value_type>* head() const {
        return head_;
    }

private:
    node<value_type> *head_;
    size_t size_;
};


template <typename T>
void print_list(const list<T>& list)
{
    std::cout << "size " << list.size() << ":\n";

    node<T> *item = list.head()->next;
    while (item != list.head())
    {
        std::cout << item->value << " ";
        item = item->next;
    }

    std::cout << "\n";
}

