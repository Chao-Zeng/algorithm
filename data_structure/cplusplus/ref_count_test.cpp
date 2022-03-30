#include "ref_count.h"

#include <iostream>

class ref_count_test : public ref_count_base
{
private:
    int num_{0};
public:
    ref_count_test() {
        std::cout << __func__ << std::endl;
    }

    ~ref_count_test() {
        std::cout << __func__ << std::endl;
    }

    void set_num(int num) {
        num_ = num;
    }

    void add() {
        ++num_;
    }

    void print() {
        std::cout << "num is " << num_ << std::endl;
    }

    void share_from_this() {
        scope_ptr<ref_count_test> self(this);
        std::cout << "ref count " << self->use_count() << std::endl;
        self->print();

    }
};

void func(scope_ptr<ref_count_test> obj)
{
    std::cout << "ref count " << obj->use_count() << std::endl; // 4
    obj->add();
    obj->print(); // 13
    (*obj).set_num(100);
}

// compile error, not derive from ref_count_base
// class Obj {};
// scope_ptr<Obj> ptr;

int main ()
{
    scope_ptr<ref_count_test> obj1(new ref_count_test);
    obj1->set_num(10);
    std::cout << "ref count " << obj1->use_count() << std::endl; // 1
    obj1->print(); // 10

    scope_ptr<ref_count_test> obj2(obj1);
    (*obj2).add();
    scope_ptr<ref_count_test> obj3 = obj2;
    obj3->add();

    std::cout << "ref count " << obj1->use_count() << std::endl; // 3
    obj1->print(); // 12

    func(obj2);

    std::cout << "ref count " << obj1->use_count() << std::endl; // 3
    obj1->print(); // 100

    obj1->share_from_this();

    return 0;
}

