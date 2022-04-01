#pragma once

#include <atomic>
#include <type_traits>

class ref_count_base
{
public:
    int use_count() {
        return count_;
    }

protected:
    ref_count_base() = default;
    virtual ~ref_count_base() = default;

    void add_ref() {
        ++count_;
    }

    void remove_ref() {
        if (--count_ == 0)
        {
            delete this;
        }
    }

    template<typename T>
    friend class scope_ptr;

private:
    std::atomic<int> count_{0};
};

template<typename T>
class scope_ptr
{
    static_assert(std::is_base_of<ref_count_base, T>::value, "ref_count_base is not base of T");
public:
    scope_ptr() : obj_(nullptr) {}
    scope_ptr(T *obj) : obj_(obj) {
        if (obj_)
        {
            obj_->add_ref();
        }
    }

    scope_ptr(const scope_ptr& r) {
        obj_ = r.obj_;
        if (obj_)
        {
            obj_->add_ref();
        }        
    }

    scope_ptr& operator=(const scope_ptr& r) {
        obj_ = r.obj_;
        if (obj_)
        {
            obj_->add_ref();
        }
    }

    scope_ptr(scope_ptr&& r) {
        obj_ = r.obj_;
        r.obj_ = nullptr;
    }

    scope_ptr& operator=(scope_ptr&& r) {
        obj_ = r.obj_;
        r.obj_ = nullptr;
    }

    ~scope_ptr() {
        if (obj_)
        {
            obj_->remove_ref();
        }
    }

    T& operator*() {
        return *obj_;
    }

    T* operator->() {
        return obj_;
    }

    void swap(scope_ptr &other) {
        T *tmp = obj_;
        obj_ = other.obj_;
        other.obj_ = tmp;
    }

private:
    T *obj_;
};
