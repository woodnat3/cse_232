//Nate Wood
#include<iostream>
using std::cout; using std::endl;

#include "proj09_class.h"
using student::MVM;

int main(){
    cout << "hi" << endl;
    MVM mvm1({ {"abc", {"a","b", "c"}},
        {"xyz", {"x","y","z"}}
    });
    cout << mvm1;
}

