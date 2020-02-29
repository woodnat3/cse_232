//Nate Wood
#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;

template <typename T>
struct Node{
public:
    Node *next_;
    T data_;
    
    Node() : data_( T() ), next_(nullptr) {};
    Node(T d) : data_(d), next_(nullptr) {};
};

template <typename T>
class SingleLink{
private:
    Node<T> *head_;
    Node<T> *tail_;
    
public:
    SingleLink();
    SingleLink(T dat);
    void append_back(T);
    friend ostream& operator<<(ostream &out, SingleLink<T>& s){
        Node<T> *next = s.head_;
        while ((*next).next_ != nullptr){
            out << (*next).data_ << ",";
            Node<T> *next = (*next).next_;
        }
        out << (*next).data_;
        return out;
    };
    bool del(T val);
    Node<T>& operator[](size_t index);
    
    // Rule of three stuff, if you get time. Look at 21.2
    ~SingleLink();
    SingleLink(const SingleLink &);
    SingleLink& operator=(SingleLink);
    
};
template <typename T>
void SingleLink<T>::append_back(T dat){
    Node<T> n(dat);
    if (tail_ == nullptr and head_ == nullptr){
        cout << "here" << endl;
        head_ = &n;
        tail_ = &n;
    }
    else{
        tail_->next_ = &n;
        tail_ = nullptr;
        tail_ = &n;
    }
}
template <typename T>
SingleLink<T>::SingleLink(){
    head_ = nullptr;
    tail_ = nullptr;
}
template <typename T>
SingleLink<T>::SingleLink(T dat){
    Node<T> n(dat);
    head_ = &n;
    tail_ = &n;
}
template <typename T>
SingleLink<T>::~SingleLink(){
    head_ = nullptr;
    tail_ = nullptr;
}
//template <typename T>
//Node<T>& SingleLink<T>::operator[](size_t index){
//    
//}
#endif
