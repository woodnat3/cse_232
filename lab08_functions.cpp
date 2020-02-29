//Nate Wood

#include "lab08_functions.h"
#include<vector>
using std::vector;
#include<string>
using std::string; using std::to_string;
#include<map>
using std::map;
#include<utility>
using std::pair; using std::get;
#include<stdexcept>
using std::out_of_range; using std::range_error;
#include<iostream>
using std::cout; using std::endl;

using collatz_map = map<long, vector<long>>;
using Collatz = pair<long, vector<long> >;

long collatz_next(long n){
    try{
        if (n < 1){
            throw range_error("range_error");
        }
        else{
            if (n % 2 == 0){
                n = n / 2;
            }
            else{
                n = 3 * n + 1;
            }
            return n;
        }
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
        return 0;
    }
}
string Collatz_to_string(const Collatz &p){
    string result = "";
    long num = p.first;
    result += to_string(num);
    result += ": ";
    vector<long> lst = p.second;
    for (auto c : lst){
        result += to_string(c);
        if (c != lst[lst.size()-1]){
            result += ",";
        }
    }
    return result;
}
//string sequence_in_map_to_string(map<long, vector<long> > &m, long number){
//
//}
vector<long> collatz_sequence(map<long, vector<long> > &m, long number){
    if (m.find(number) == m.end()){
        vector<long> result = {};
        long num = number;
        while (num > 1){
            long x = collatz_next(num);
            result.push_back(x);
            num = x;
        }
        return result;
    }
    else{
        vector<long> result = m[number];
        return result;
    }
}
void collatz_range(map<long, vector<long> > &m, long low, long high){
    for (long i = low; i < high + 1; i++){
        Collatz p;
        vector<long> sequence = collatz_sequence(m, i);
        p.first = i;
        p.second = sequence;
        m.insert(p);
    }
}
