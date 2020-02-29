//Nate Wood

#include "proj07_functions.h"

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
#include<utility>
using std::pair;

using map_type = map<string, long >;

int main(){
    const map_type m;
    pair<string, long> p1;
    pair<string, long> p2;
    p1.first = "s";
    p1.second = 2;
    p2.first = "a";
    p2.second = 3;
    m.insert(p1);
    m.insert(p2);
    double denom = (4 + 5 - 2);
    cout << denom << endl;
    double ans = 2/denom;
    cout << ans << endl;
    string c = "s";
    cout << m[c];
}
