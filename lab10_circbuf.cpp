//Nate Wood

#include "lab10_circbuf.h"
#include<exception>
using std::runtime_error;
CircBuf::CircBuf(size_t s){
    sz_ = static_cast<int>(s);
    buf_.resize(s);
}
CircBuf::CircBuf(initializer_list<long> l, size_t n){
    try{
        if (l.size() < n){
            buf_.resize(n);
            copy(l.begin(), l.end(), buf_.begin());
        }
        else{
            throw runtime_error("wrong size");
        }
    }
    catch(runtime_error& e){
        
    }
}
long CircBuf::front() const{
    try{
        if (empty()){
            throw runtime_error("no value");
        }
        else{
            return buf_[head_];
        }
    }
    catch(runtime_error& e){
        return 0;
    }
}
long CircBuf::back() const{
    try{
        if (empty()){
            throw runtime_error("no value");
        }
        else{
            return buf_[tail_ - 1];
        }
    }
    catch(runtime_error& e){
        return 0;
    }
}
bool CircBuf::full() const{
    if (cnt_ == sz_){
        return true;
    }
    else{
        return false;
    }
}
bool CircBuf::empty() const{
    if (cnt_ == 0){
        return true;
    }
    else{
        return false;
    }
}
void CircBuf::add(long num){
    try{
        if (full() == false){
            buf_[tail_] = num;
            tail_ = (tail_ + 1) % sz_;
        }
        else{
            throw runtime_error("full");
        }
    }
    catch(runtime_error& e){
        
    }
}
void CircBuf::remove(){
    try{
        if (empty() == false){
            head_ = (head_ + 1) % sz_;
        }
        else{
            throw runtime_error("empty");
        }
    }
    catch(runtime_error& e){
        
    }
}
friend ostream& operator<<(ostream &out, const CircBuf &cb){
    out << buf_[head_] << " " << buf_[tail_ - 1];
    
}
