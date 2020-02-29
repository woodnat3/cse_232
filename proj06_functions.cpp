//Nate Wood

#include "proj06_functions.h"
#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<vector>
using std::vector;

ostream& print_vector(const vector<long>& v, ostream& out){//prints the vector to the provided ostream with a comma between each number
    for (auto c : v){
        out << c;
        if (c != v.back()){
            out << ",";
        }
    }
    return out;
}
long four_corner_sum(const vector<long>& v, int rows, int cols){//takes the four corners of the 2D vector and returns the sum of all of them
    if (rows > 1 && cols > 1){
        long total = 0;
        int index = (rows*cols - cols);
        total += v[0];//top left corner
        total += v.back();//bottom right corner
        total += v[cols-1];//top right corner
        total += v[index];//bottom left corner
        return total;
    }
    else{
        return 0;
    }
}
vector<long> rotate_rows_up(const vector<long>& v, int rows, int cols){//takes the first row and moves it to the bottom moving every other row up one
    vector<long> result = {};
    if (rows > 1){
        for (int i = cols; i < cols*rows; i++){//adds all but the first row to the new vector
            result.push_back(v[i]);
        }
        for (int i = 0; i < cols; i++){//adds the first row of the vector to the new vector after
            result.push_back(v[i]);
        }
    }
    return result;
}
vector<long> column_order(const vector<long>&v , int rows, int cols){//makes a new vector in order of columns instead of rows
    vector<long> result = {};
    for (int i = 0; i < cols; i++){
        for (int n = 0; n < rows; n++){
            long index = (cols * n) + i;
            result.push_back(v[index]);//adds the values from the same column to the new vector first then every other column after
        }
    }
    return result;
}
vector<long> matrix_ccw_rotate(const vector<long>& v, int rows, int cols){//makes a new vector by rotating the old one 90 degrees
    vector<long> result = {};
    for (int n = cols-1; n >= 0; n--){//takes the last value from each row and adds it to the vector, then adds the values from the columns to the left of it in order
        for (int i = 0; i < rows; i++){
            long index = (cols * i) + n;
            result.push_back(v[index]);
        }
    }
    return result;
}
long max_column_diff(const vector<long>& v, int rows, int cols){//takes the total sum of the values from each column and finds the maximum difference between each column
    vector<long> sums = {};
    for (int i = 0; i < cols; i++){
        long sum = 0;
        for (int n = 0; n < rows; n++){//finds sum of values in each column and adds it to the list
            long index = (cols * n) + i;
            sum += v[index];
        }
        sums.push_back(sum);
    }
    long max = 0;
    for (auto c : sums){//goes through the list of sums, compares them and keeps track of the maximum difference
        for (auto x : sums){
            long diff = c - x;
            if (diff > max){
                max = diff;
            }
        }
    }
    return max;
}
bool check_neighbors(const vector<long>& v, int rows, int cols, long e){//series of if statements to test if a value is trapped
    if (e < cols){//changes index if top row
        long index1 = rows*cols - (cols-e);
        if (v[index1] <= v[e]){
            return false;
        }
    }
    else{
        long index1 = e - cols;
        if (v[index1] <= v[e]){
            return false;
        }
    }
    if (e % cols == 0){//changes index if far left column
        long index2 = e + cols - 1;
        if (v[index2] <= v[e]){
            return false;
        }
    }
    else{
        long index2 = e - 1;
        if (v[index2] <= v[e]){
            return false;
        }
    }
    if (e % cols == cols-1){//changes index if far right column
        long index3 = e - (cols - 1);
        if (v[index3] <= v[e]){
            return false;
        }
    }
    else{
        long index3 = e + 1;
        if (v[index3] <= v[e]){
            return false;
        }
    }
    if (e > (rows*cols)-cols){//changes index if bottom row
        long index4 = e % cols;
        if (v[index4] <= v[e]){
            return false;
        }
    }
    else{
        long index4 = e + cols;
        if (v[index4] <= v[e]){
            return false;
        }
    }
    return true;//if the value passes each if statement then the value is trapped and returns true
}
long trapped_vals(const vector<long>& v, int rows, int cols){//takes the index of each value and tests if the value is trapped using check_neighbors()
    long count = 0;
    for (long i = 0; i < v.size(); i++){
        bool ans = check_neighbors(v, rows, cols, i);
        if (ans){//if true is returned then the value is trapped and the count is increased by 1
            count += 1;
        }
    }
    return count;
}
