//Nate Wood

#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

#include "lab13_singlelink.h"

int main () {    
    SingleLink<string> sl("a");
    sl.append_back("b");
    cout << sl << endl;
}
