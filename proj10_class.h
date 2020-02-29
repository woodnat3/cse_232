//Nate Wood

#pragma once
#include<iostream>
using std::cout; using std::endl; using std::boolalpha; using std::ostream;
#include<initializer_list>
using std::initializer_list;
#include <algorithm>
using std::max; using std::copy; using std::swap; using std::move;
#include <utility>
using std::make_pair; using std::pair;
#include <stdexcept>
using std::runtime_error;
#include<vector>
using std::vector;

const static size_t element_array_size = 5;

template<typename K, typename V>
struct Element{//defines Element struct
public:
    K key_;
    V values_[element_array_size];
    size_t count_ = 0;
    Element()=default;
    Element(K key, initializer_list<V> values);
    bool operator==(const Element&)const;
    bool operator<(const K&) const;
    friend ostream& operator<<(ostream& o, Element& e){//defines the << operator
        o << e.key_ << ":";
        for (long i = 0; i < e.count_-1; i++){
            o << e.values_[i] << ",";
        }
        o << e.values_[e.count_-1];
        return o;
    }
    
};
template <typename K, typename V>//constructs Element from a key and a list of values
Element<K, V>::Element(K key, initializer_list<V> values){
    key_ = key;
    count_ = values.size();
    copy(values.begin(), values.end(), values_);
}
template <typename K, typename V>
bool Element<K, V>::operator==(const Element& e)const{//compares two Elements based on the key and the values
    if (key_ != e.key_){
        return false;
    }
    else if (count_ != e.count_){
        return false;
    }
    else{
        for (long i = 0; i < count_; i++){
            if (values_[i] != e.values_[i]){
                return false;
            }
        }
        return true;
    }
}
template <typename K, typename V>
bool Element<K, V>::operator<(const K& key) const{//compares two Elements based on the keys
    if (key_ < key){
        return true;
    }
    else{
        return false;
    }
}
template<typename K, typename V>
class MVM{//defines the MVM class
public:
    Element<K, V> * data_ = nullptr;
    size_t num_keys_ = 0;
    size_t num_elements_ = 0;
    Element<K, V> * find_key(K);
    size_t find_value(V, K*&);
    void grow();
    
public:
    MVM()=default;
    MVM(initializer_list<Element<K,V>>);
    MVM(const MVM&);
    ~MVM();
    size_t size();
    bool add(K,V);
    bool remove_key(K);
    size_t remove_value(V, K*&);
    friend ostream& operator<<(ostream& oss, MVM& mv){//defines the << operator
        size_t count = 1;
        for (long x = 0; x < mv.num_keys_; x++){
            oss << mv.data_[x].key_ << ":";
            for (long i = 0; i < mv.data_[x].count_-1; i++){
                oss << mv.data_[x].values_[i] << ",";
            }
            oss << mv.data_[x].values_[mv.data_[x].count_-1];
            if (count < mv.num_keys_){
                oss << " ";
            }
            count += 1;
        }
        return oss;
    }
};
template <typename K, typename V>
MVM<K, V>::MVM(initializer_list<Element<K, V>> lst){//constructs an MVM from a list of Elements
    num_keys_ = lst.size();
    num_elements_ = lst.size();
    data_ = new Element<K, V>[num_elements_];
    copy(lst.begin(), lst.end(), data_);
}
template <typename K, typename V>
Element<K, V>* MVM<K, V>::find_key(K key){//finds pointers to keys using lower_bound
    if (data_ != nullptr){
        return lower_bound(data_, (data_+(num_keys_-1)), key);
    }
    else{
        return nullptr;
    }
}
template <typename K, typename V>
size_t MVM<K, V>::find_value(V val, K* (&keys_found)){//finds values in MVM Elements
    vector<K> temp = {};
    if (keys_found == nullptr){
        size_t count = 0;
        for (size_t i = 0; i < num_keys_; i++){
            for (V value : data_[i].values_){
                if (val == value){
                    temp.push_back(data_[i].key_);
                    count += 1;
                }
            }
        }
        if (count > 0){
            keys_found = new K[count];
            for (size_t i = 0; i < count; i++){
                keys_found[i] = temp[i];
            }
        }
        return count;
    }
    else{
        throw runtime_error("array not empty");
    }
}
template <typename K, typename V>
void MVM<K, V>::grow(){//increases the size of data_ in an MVM
    if (data_ != nullptr){
        num_elements_ *= 2;
        Element<K, V>* new_data = new Element<K, V>[num_elements_];
        copy(data_, data_+num_keys_, new_data);
        data_ = nullptr;
        data_ = new Element<K, V>[num_elements_];
        copy(new_data, new_data+num_keys_, data_);
        delete[]new_data;
    }
    else{
        num_elements_ = 2;
        data_ = new Element<K, V>[num_elements_];
        
    }
}
template <typename K, typename V>
bool MVM<K, V>::add(K key, V value){//adds new Elements or new values to Elements based on whether the given key already exists or not
    cout << *this << endl;
    if (data_ != nullptr){
        auto it = find_key(key);
        if (it->key_== key){
            if (it->count_ == element_array_size){
                return false;
            }
            else{
                for (long i = 0; i < it->count_; i++){
                    if (it->values_[i] == value){
                        return false;
                    }
                }
                it->values_[it->count_] = value;
                it->count_ += 1;
                //auto loc = lower_bound(it->values_, it->values_ + it->count_, value);
                //rotate(loc, it->values_ + it->count_ - 1, it->values_ + it->count_);
            }
        }
        else{
            if (num_keys_ >= num_elements_){
                grow();
            }
            Element<K, V> e;
            e.count_ = 1;
            e.key_ = key;
            e.values_[0] = value;
            data_[num_keys_] = e;
            num_keys_ += 1;
            auto it2 = find_key(key);
            rotate(it2, data_ + num_keys_ - 1, data_ + num_keys_);
        }
    }
    else{
        grow();
        Element<K, V> e;
        e.count_ = 1;
        e.key_ = key;
        e.values_[0] = value;
        data_[0] = e;
        num_keys_ = 1;
    }
    return true;
}
template <typename K, typename V>
size_t MVM<K, V>::size(){//returns num_keys_ of an MVM
    return num_keys_;
}
template <typename K, typename V>
bool MVM<K, V>::remove_key(K key){//removes keys from an MVM
    Element<K, V>* new_data = new Element<K, V>[num_keys_];
    bool good = false;
    size_t count = 0;
    size_t key_itr;
    for (size_t i = 0; i < num_keys_; i++){
        if (data_[i].key_ == key){
            good = true;
            key_itr = i;
        }
    }
    if (good){
        auto it = find_key(key);
        rotate(it, it+1, data_ + num_keys_);
        for (size_t i = 0; i < num_keys_ - 1; i++){
            new_data[count] = data_[i];
            count += 1;
        }
        delete[]data_;
        copy(new_data, new_data + num_keys_-1, data_);
        delete[]new_data;
        num_keys_ -= 1;
        return true;
    }
    else{
        return false;
    }
}
template <typename K, typename V>
size_t MVM<K, V>::remove_value(V val, K* (&keys_found)){//removes values from MVM Elements' values
    size_t count = 0;
    if (keys_found == nullptr){
        for (size_t i = 0; i < num_keys_; i ++){
            for (size_t x = 0; x < data_[i].count_; x++){
                if (data_[i].values_[x] == val){
                    count += 1;
                }
            }
        }
        keys_found = new K[count];
        long key_count = 0;
        for (size_t i = 0; i < num_keys_; i ++){
            auto it = lower_bound(data_[i].values_, data_[i].values_ + data_[i].count_, val);
            if (*it == val){
                auto it2 = lower_bound(data_, data_ + num_keys_, data_[i].key_);
                keys_found[key_count] = it2->key_;
                rotate(it, it+1, it2->values_ + it2->count_);
                V new_values[element_array_size];
                for (long temp = 0; temp < it2->count_-1; temp++){
                    new_values[temp] = it2->values_[temp];
                }
                cout << "\n" << "here: ";
                for (int t = 0; t < it2->count_-1; t++){
                    cout << *(new_values + t) << ",";
                }
                cout << endl;
                swap(it2->values_, new_values);
                key_count += 1;
                break;
            }
        }
    }
    else{
        throw runtime_error("array not empty");
    }
    return count;
}
template <typename K, typename V>
MVM<K, V>::~MVM(){//defines the dtor
    delete[]data_;
}
// Code for MVM functions goes here
