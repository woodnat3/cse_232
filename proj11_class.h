//Nate Wood

#pragma once
#include<iostream>
using std::cout; using std::endl; using std::boolalpha; using std::ostream;
#include<initializer_list>
using std::initializer_list;
#include <algorithm>
using std::max; using std::copy; using std::swap;
#include <utility>
using std::make_pair; using std::pair;
#include <stdexcept>
using std::runtime_error;
#include<iterator>
using std::begin; using std::end;

const static size_t element_array_size = 5;

template<typename K, typename V>
struct Element{//defines the Element struct
public:
    K key_;
    V values_[element_array_size];
    Element* next_ = nullptr;
    
    //Optional
    //Element* previous = nullptr;
    
    size_t count_ = 0;
    
    Element()=default;
    Element(K, initializer_list<V>);
    Element(const Element&);
    bool operator==(const Element&)const;
    bool operator<(const K&) const;
    friend ostream& operator<<(ostream& oss, Element& ele){//defines the << operator for Element
        oss << ele.key_ << ":";
        for (size_t i = 0; i < ele.count_-1; i++){
            oss << ele.values_[i] << ",";
        }
        oss << ele.values_[ele.count_-1];
        return oss;
    }
    
};
template <typename K, typename V>
Element<K, V>::Element(K key, initializer_list<V> lst){//constructs an Element from a key and a list of values
    key_ = key;
    count_ = lst.size();
    copy(lst.begin(), lst.end(), values_);
    next_ = nullptr;
}
template <typename K, typename V>
bool Element<K, V>::operator==(const Element<K, V> &e)const{//defines the == operator for Element
    if (count_ != e.count_){
        return false;
    }
    else if (key_ != e.key_){
        return false;
    }
    else{
        for (long i = 0; i < count_; i++){
            if (values_[i] != e.values_[i]){
                return false;
            }
        }
    }
    return true;
}
template <typename K, typename V>
bool Element<K, V>::operator<(const K &key)const{//defines the < operator for Element
    if (key_ < key){
        return true;
    }
    else{
        return false;
    }
}
template <typename K, typename V>
Element<K, V>::Element(const Element &e){//defines the copy constructor for Element
    count_ = e.count_;
    key_ = e.key_;
    next_ = nullptr;
    copy(e.values_, e.values_ + element_array_size, values_);
}
template<typename K, typename V>
class MVM{//defines the MVM class
public:
    Element<K, V> * data_head_ = nullptr;
    
    //optional
    //Element<K, V> * data_tail_ = nullptr;
    //size_t num_elements_ = 0;
    
    size_t num_keys_ = 0;
    
    pair <Element<K,V>*, Element<K,V> *> find_key(K);
    MVM find_value(V);
    
public:
    //Constructors
    MVM()=default;
    MVM(initializer_list<pair<K,initializer_list<V>>>);
    
    //Rule of Three
    MVM(const MVM&);
    MVM& operator=(const MVM& other);
    ~MVM();
    
    //Other Functions
    size_t size();
    bool add(K,V);
    bool remove_key(K);
    MVM remove_value(V);
    
    friend ostream& operator<<(ostream& oss, MVM& mv){//defines the << operator for MVM
        for (Element<K, V> *ptr = mv.data_head_; ptr != nullptr; ptr = ptr->next_){
            oss << *ptr;
            if (ptr->next_ != nullptr){
                oss << " ";
            }
        }
        return oss;
    }
};
template <typename K, typename V>
MVM<K, V>::MVM(initializer_list<pair<K, initializer_list<V>>> lst){//constructs an MVM from a list of pairs containing keys and lists of values
    num_keys_ = lst.size();
    size_t i = 0;
    Element<K, V> *prev;
    for (pair<K, initializer_list<V>> p : lst){
        Element<K, V> *e = new Element<K, V>(p.first, p.second);
        if (i == 0){
            data_head_ = e;
        }
        else if (i == num_keys_-1){
            e->next_ = nullptr;
            prev->next_ = e;

        }
        else{
            prev->next_ = e;
        }
        i++;
        prev = e;
    }
}
template <typename K, typename V>
MVM<K, V>::MVM(const MVM& other){//defines the copy constructor for MVM
    num_keys_ = other.num_keys_;
    data_head_ = other.data_head_;
}
template <typename K, typename V>
MVM<K, V>::~MVM(){//defines the dtor for MVM
    Element<K, V> *to_del = data_head_;
//    while (to_del != nullptr){
//        data_head_ = data_head_->next_;
//        if (to_del != nullptr){
//            delete to_del;
//        }
//        to_del = data_head_;
//    }
    data_head_ = nullptr;
}
template <typename K, typename V>
pair<Element<K, V>*, Element<K, V>*> MVM<K, V>::find_key(K key){//takes a key and searches through each Element in the MVM to find it, returns a pair containing
    pair<Element<K, V>*, Element<K, V>*> p;
    Element<K, V> *e = data_head_;
    while (e->next_ != nullptr){
        if (e->key_ >= key){
            p.first = nullptr;
            p.second = e;
            return p;
        }
        else if (e->next_->key_ >= key){
            p.first = e;
            p.second = (e->next_);
            return p;
        }
        e = e->next_;
    }
    p.first = nullptr;
    p.second = nullptr;
    return p;
}
template <typename K, typename V>
MVM<K, V> MVM<K, V>::find_value(V val){//searches through the MVM for each element containing the inputted value, creates an MVM with each key and the value inputted
    initializer_list<pair<K, initializer_list<V>>> lst;
    Element<K, V> *ptr;
    long count = 0;
    pair<K, initializer_list<V>>* ary = new pair<K, initializer_list<V>>[num_keys_];
    for (ptr = data_head_; ptr != nullptr; ptr = ptr->next_){
        for (long i = 0; i < ptr->count_; i++){
            if (ptr->values_[i] == val){
                pair<K, initializer_list<V>> p;
                p.first = ptr->key_;
                p.second = {val};
                count += 1;
            }
        }
    }//I tried something new but it was a dead end......
    cout << (*ary).first << endl;
    //lst = {*ary};
    //copy(ary, ary+count, lst.begin());
    return MVM(lst);
}
template <typename K, typename V>
bool MVM<K, V>::add(K key, V val){//adds a key and value to an MVM, if either exist then it isn't added. Returns true if either are added, false if neither are added
    auto p = find_key(key);
    cout << *p.first << " " << *p.second << " pairs" << endl;
    if (p.second->key_ == key){
        for (long i = 0; i < p.second->count_; i++){
            if (p.second->values_[i] == val){
                return false;
            }
        }
        if (p.second->count_ == element_array_size){
            return false;
        }
        else{
            p.second->values_[p.second->count_] = val;
            p.second->count_ += 1;
            return true;
        }
    }
    else{
        Element<K, V> e(key, {val});
        if (p.second == nullptr){
            p.first->next_ = &e;
        }
        else if (p.first == nullptr){
            e.next_ = p.second;
            data_head_ = &e;
        }
        else{
            e.next_ = &*p.second;
            data_head_->next_ = &e;
        }
        cout << *data_head_ << " " << *data_head_->next_ << " " << *data_head_->next_->next_ << " " << *data_head_->next_->next_->next_ << endl;
        num_keys_ += 1;
        return true;
    }
}
template <typename K, typename V>
size_t MVM<K, V>::size(){//returns num_keys_, the size of the MVM
    return num_keys_;
}
template <typename K, typename V>
bool MVM<K, V>::remove_key(K key){//searches through the MVM to remove a key, returns true if it was removed, false if it wasn't
    Element<K, V> *ptr;
    Element<K, V> *last = nullptr;
    for (ptr = data_head_; ptr != nullptr; ptr = ptr->next_){
        if (ptr->key_ == key){
            if (last == nullptr){
                data_head_ = data_head_->next_;
                ptr = nullptr;
            }
            else{
                last->next_ = ptr->next_;
                ptr = nullptr;
                last = nullptr;
            }
            num_keys_ -= 1;
            return true;
        }
        last = ptr;
    }
    return false;
}
template <typename K, typename V>
MVM<K, V> MVM<K, V>::remove_value(V val){//searches through the MVM and removes the inputted value from each Element containing it. returns an MVM with each key and the val
    //I was so very confused I am so sorry :(. I still dont know how to remove values from an array...
}
