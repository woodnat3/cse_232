//Nate Wood

#include "lab11_arrays.h"
#include<fstream>
using std::ifstream;
#include<stdexcept>
using std::runtime_error;
#include<iostream>
using std::cout; using std::endl;

bool is_even(long l){
    if (l % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}
void print_array(long ary[], size_t sz, ostream& out){
    for (int i = 0; i < sz-1; i++){
        out << ary[i] << ", ";
    }
    out << ary[sz-1];
}
size_t fill_from_file(long* (& ary), string f_name){
    ifstream file;
    size_t size = 0;
    file.open(f_name);
    if (file.fail()){
        throw runtime_error("file not found");
    }
    file >> size;
    ary = new long[size];
    long num;
    long index = 0;
    while (file >> num){
        ary[index] = num;
        index += 1;
    }
    return size;
}
size_t concatenate(long* (& ary1), size_t sz1, long ary2[], size_t sz2){
    long size = sz1 + sz2;
    long* temp = new long[size]{};
    for (int i = 0; i < sz1; i++){
        temp[i] += ary1[i];
    }
    for (int i = 0; i < sz2; i++){
        temp[i + sz1] += ary2[i];
    }
    delete ary1;
    ary1 = temp;
    return size;
}
pair<long*, size_t> copy_evens(long ary[], size_t sz){
    pair<long*, size_t> p;
    size_t size = 0;
    for (int i = 0; i < sz; i++){
        bool ans = is_even(ary[i]);
        if (ans){
            size += 1;
        }
    }
    p.second = size;
    long index = 0;
    long* temp = new long[size]{};
    for (int i = 0; i < sz; i++){
        bool ans = is_even(ary[i]);
        if (ans){
            temp[index] += ary[i];
            index += 1;
        }
    }
    p.first = temp;
    return p;
}
