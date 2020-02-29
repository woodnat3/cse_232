//Nate Wood

#pragma once

#include<initializer_list>
using std::initializer_list;
#include<stdexcept>
using std::range_error;
#include<algorithm>
using std::copy; using std::swap;


namespace student{
    template<typename t>
    class vector{
    private:
        size_t capacity_ = 10;
        size_t size_ = 0;
        t* data_ = new t[capacity_];
    public:
        vector<t>() = default;
        vector<t>(size_t capacity);
        vector<t>(initializer_list<t> lst);
        size_t size();
        size_t capacity();
        void push_back(t val);
        t& operator[](size_t val);
        t& front();
        t& back();
        void swap(vector &v1, vector &v2);
        vector(vector& v);
        vector& operator=(vector v);
        ~vector<t>();
    };
}
using student::vector;

template <typename t>
student::vector<t>::vector(size_t capacity){
    capacity_ = capacity;
    size_ = 0;
    delete[]data_;
    data_ = new t[capacity_];
}
template <typename t>
student::vector<t>::vector(initializer_list<t> lst){
    size_ = lst.size();
    capacity_ = lst.size();
    delete[]data_;
    data_ = new t[capacity_];
    copy(lst.begin(), lst.end(), data_);
}
template <typename t>
size_t student::vector<t>::size(){
    return size_;
}
template <typename t>
size_t student::vector<t>::capacity(){
    return capacity_;
}
template <typename t>
void student::vector<t>::push_back(t val){
    if (size_ >= capacity_){
        capacity_ *= 2;
        t* new_data = new t[capacity_];
        copy(data_, data_+size_, new_data);
        delete[]data_;
        data_ = new t[capacity_];
        copy(new_data, new_data+size_, data_);
        delete[]new_data;
    }
    long size = size_;
    data_[size] = val;
    size_ += 1;
}
template <typename t>
t& student::vector<t>::operator[](size_t val){
    if (val < size_){
        t& result = data_[val];
        return result;
    }
    else{
        throw range_error("val out of range");
    }
}
template <typename t>
t& student::vector<t>::front(){
    if (size_ == 0){
        throw range_error("vector empty");
    }
    else{
        t& ref = data_[0];
        return ref;
    }
}
template <typename t>
t& student::vector<t>::back(){
    if (size_ == 0){
        throw range_error("vector empty");
    }
    else{
        t& ref = data_[size_-1];
        return ref;
    }
}
template <typename t>
student::vector<t>::vector(vector& v){
    capacity_ = v.capacity_;
    size_ = v.size_;
    delete[]data_;
    data_ = new t[capacity_];
    copy(v.data_, v.data_+v.size_, data_);
}
template <typename t>
vector<t>& student::vector<t>::operator=(vector<t> v){
    swap(*this, v);
    return *this;
}
template <typename t>
student::vector<t>::~vector(){
    delete[]data_;
}
template <typename t>
void student::vector<t>::swap(vector &v1, vector &v2){
    std::swap(v1.size_, v2.size_);
    std::swap(v1.capacity_, v2.capacity_);
    std::swap(v1.data_, v2.data_);
}
