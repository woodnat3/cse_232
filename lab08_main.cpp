//Nate Wood

#include "lab08_functions.h"
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include<iostream>
using std::cout; using std::cin; using std::endl;

using collatz_map = map<long, vector<long>>;
using Collatz = pair<long, vector<long> >;

int main(){
    collatz_map m;
    Collatz p;
    p.first = 0;
    p.second = {1, 2, 3};
    m.insert(p);
    long ans1 = collatz_next(4);
    cout << ans1 << endl;
    string ans2 = Collatz_to_string(p);
    cout << ans2 << endl;
    vector<long> ans3 = collatz_sequence(m, 0);
    for (auto c : ans3){
        cout << c << ",";
    }
    cout << endl;
}

