//Nate Wood

#include "proj09_class.h"
using student::Element; using student::MVM;
#include<iostream>
using std::cout; using std::endl;
#include<algorithm>
using std::lower_bound;
Element::Element(string str, initializer_list<string> lst){//Initializes an element
    key_ = str;
    values_ = lst;
}
MVM::MVM(initializer_list<Element> lst){//Initializes an MVM
    data_ = lst;
}
bool Element::operator==(const Element& e)const{//defines the == operator between two Elements
    if (key_ == e.key_ and values_ == e.values_){
        return true;
    }
    else{
        return false;
    }
}
ostream& operator<<(ostream& out, Element& e){// defines the << operator for Elements
    out << e.key_ << ":";
    for (auto c : e.values_){
        out << c;
        if (c != e.values_.back()){
            out << ",";
        }
    }
    return out;
}
size_t MVM::size(){//returns the size of an MVM
    size_t s = 0;
    for (auto e : data_){
        s += 1;
    }
    return s;
}
vector<Element>::iterator MVM::find_key(string s){//uses lower_bound to find the iterator of the given key and returns it
    vector<string> keys;
    for (auto e : data_){
        keys.push_back(e.key_);
    }
    return lower_bound(data_.begin(), data_.end(), s, [](const Element &elem, const string &key)
                       {
                           if (elem.key_ < key){
                               return true;
                           }
                           else{
                               return false;
                           }
                       });
}
vector<string> MVM::find_value(string s){//searches through each element in an MVM and to find a value, returns a list of every key contatining the given value
    vector<string> result = {};
    for (auto element : data_){
        for (auto c : element.values_){
            if (c == s){
                result.push_back(element.key_);
            }
        }
    }
    return result;
}
bool MVM::add(string s1,string s2){//adds a new value to an element, if the given key doesnt exist, a new one is made to hold the value
    auto it = find_key(s1);
    Element e = *it;
    if (e.key_ == s1){
        for (auto val : e.values_){
            if (val == s2){
                return false;
            }
        }
        it->values_.push_back(s2);
    }
    else{
        Element e;
        e.key_ = s1;
        e.values_.push_back(s2);
        data_.insert(it, e);
    }
    cout << *this << endl;
    return true;
}
bool MVM::remove_key(string s){//searches for a key and removes it from the MVM
    auto it = find_key(s);
    if (it != data_.end()){
        data_.erase(it);
        return true;
    }
    else{
        return false;
    }
}
vector<string> MVM::remove_value(string s){//searches for a value in an MVM and removes it from every key the value is in, returns a list where the value was removed from
    vector<string> result = {};
    for (auto e : data_){
        for (auto val : e.values_){
            if (val == s){
                auto it = find_key(e.key_);
                result.push_back(e.key_);
                auto it2 = find(it->values_.begin(), it->values_.end(), s);
                it->values_.erase(it2);
            }
        }
    }
    return result;
}
ostream& operator<<(ostream& out, MVM& m){//defines the << operator for MVMs
    Element end = m.data_.back();
    for (Element e : m.data_){
        out << e.key_ << ":";
        for (auto val : e.values_){
            if (val != e.values_.back()){
                out << val << ",";
            }
            else{
                out << val;
            }
        }
        if (e == end){
            break;
        }
        else{
            out << " ";
        }
    }
    return out;
}
