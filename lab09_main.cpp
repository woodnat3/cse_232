//Nate Wood
#include "lab09_vector.h"
#include<iostream>
using std::cout; using std::endl;

int main(){
    MathVector m1(5, 3);
    MathVector m2(2, 7);
    MathVector ans1 = m1.add(m2);
    cout << ans1.x << endl;
    cout << vec_to_str(ans1) << endl;
}
