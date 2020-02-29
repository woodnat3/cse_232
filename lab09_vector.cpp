//Nate Wood
#include "lab09_vector.h"
#include<string>
using std::string; using std::to_string;
#include<cmath>
using std::pow;
#include<iostream>
using std::cout; using std::endl;
MathVector::MathVector(long x_, long y_){
    x = x_;
    y = y_;
}
MathVector MathVector::add (const MathVector& m){
    MathVector result;
    result.x = x + m.x;
    result.y = y + m.y;
    return result;
}
MathVector MathVector::mult(long num){
    MathVector result;
    result.x = x * num;
    result.y = y * num;
    return result;
}
long MathVector::mult(const MathVector& m){
    long result = x * m.x + y * m.y;
    return result;
}
double MathVector::magnitude(){
    long math = pow(x, 2) + pow(y, 2);
    double result = pow(math, .5);
    return result;
}
string vec_to_str(const MathVector& m){
    string result = "";
    result += to_string(m.x);
    result += ":";
    result += to_string(m.y);
    return result;
}
