//Nate Wood
#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include <iomanip>
using std::setw; using std::right;
#include<sstream>
using std::ostringstream;
#include "lab07_functions.hpp"
using matrix_row = vector<long>;
using matrix = vector<matrix_row>;

string matrix_to_str(const matrix &m1, size_t width){
    ostringstream result;
    unsigned long count = 0;
    for (auto c : m1){
        for (auto e : c){
            result << right << setw(int(width)) << e;
        }
        count += 1;
        if (count < m1.size()){
            result << endl;
        }
    }
    string str = result.str();
    return str;
}
bool same_size(matrix &m1, matrix &m2){
    int m1_rows = 0;
    int m2_rows = 0;
    int m1_columns = 0;
    int m2_columns = 0;
    for (auto c : m1){
        m1_rows += 1;
        for (auto e : c){
            m1_columns += 1;
        }
    }
    for (auto c : m2){
        m2_rows += 1;
        for (auto e : c){
            m2_columns += 1;
        }
    }
    if (m1_rows == m2_rows && m1_columns == m2_columns){
        return true;
    }
    else{
        return false;
    }
}
matrix add(matrix &m1, matrix &m2){
    matrix result = {};
    if (m1.size() > 0 and m2.size() > 0){
        if (same_size(m1, m2)){
            for (int i = 0; i < m1.size(); i++){
                matrix_row row = {};
                for (int n = 0; n < m1[i].size(); n++){
                    long term1 = m1[i][n];
                    long term2 = m2[i][n];
                    long ans = term1 + term2;
                    row.push_back(ans);
                }
                result.push_back(row);
            }
            return result;
        }
        else{
            return result;
        }
    }
    else{
        return result;
    }
}
matrix scalar_multiply(matrix &m, long val){
    matrix result = {};
    if (m.size() > 0){
        for (auto c : m){
            matrix_row row = {};
            for (auto e : c){
                long ans = e * val;
                row.push_back(ans);
            }
            result.push_back(row);
        }
        return result;
    }
    else{
        return result;
    }
}
