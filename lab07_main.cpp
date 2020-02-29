//Nate Wood
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::skipws; using std::boolalpha;
#include<vector>
using std::vector;
using matrix_row = vector<long>;
using matrix = vector<matrix_row>;
#include "lab07_functions.hpp"
int main(){
    cout << boolalpha;
    size_t width = 3;
    matrix_row row1 = {1, 2, 3};
    matrix_row row2 = {4, 5, 6};
    matrix_row row3 = {7, 8, 9};
    matrix m1 = {row1, row2, row3};
    matrix m2 = m1;
    string str = matrix_to_str(m1, width);
    cout << str << endl;
    bool ans = same_size(m1, m2);
    cout << ans << endl;
    matrix result1 = add(m1, m2);
    str = matrix_to_str(result1);
    cout << str << endl;
    matrix result2 = scalar_multiply(m1, 5);
    str = matrix_to_str(result2);
    cout << str << endl;
}
