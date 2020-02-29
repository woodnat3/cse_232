//Nate Wood

#include "proj06_functions.h"
#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<vector>
using std::vector;
#include<sstream>
using std::ostringstream;
#include<cassert>

int main(){
    vector<long> v = {1};
    int rows = 3;
    int cols = 4;
//    long ans1 = four_corner_sum(v, rows, cols);
//    cout << ans1 << endl;
//    vector<long> ans2 = column_order(v, rows, cols);
//    for (auto c : ans2){
//        cout << c << ",";
//    }
//    cout << endl;
//    vector<long> ans3 = rotate_rows_up(v, rows, cols);
//    for (auto c : ans3){
//        cout << c << ",";
//    }
//    cout << endl;
//    vector<long> ans4 = matrix_ccw_rotate(v, rows, cols);
//    for (auto c : ans4){
//        cout << c << ",";
//    }
//    cout << endl;
//    long ans5 = max_column_diff(v, rows, cols);
//    cout << ans5 << endl;
    long ans6 = trapped_vals(v, rows, cols);
    cout << ans6 << endl;
}
