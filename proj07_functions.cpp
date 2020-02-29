//Nate Wood

#include "proj07_functions.h"

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using std::ostream; using std::cout; using std:: endl;
#include<map>
using std::map; using std::find;
#include<fstream>
using std::ifstream;
#include<utility>
using std::pair;
#include<cmath>
using std::pow;

using map_type = map<string, long >;

ostream& print_vector (ostream &out, const vector<string> &v){//prints each element in a vector separated by commas to an ostream, returns the ostream
    for (auto c : v){
        out << c;
        if (c != v.back()){
            out << ",";
        }
    }
    return out;
}
string clean_word(const string& s){//takes a string and returns a new string that contains every alphabetical character from the inputted string
    string result = "";
    for (auto c : s){
        if (isalpha(c)){
            result += tolower(c);
        }
    }
    return result;
}
vector<string> split(const string &s, char delim){//takes a string and splits it anywhere a delimeter character shows up in the string. takes each split string and adds it to a vector which is returned
    vector<string> result = {};
    string str = "";
    for (auto c : s){
        if (c == delim){
            result.push_back(str);//string added to the vector
            str = "";
        }
        else{
            str += c;
        }
    }
    result.push_back(str);
    return result;
}
bool process_words(map_type& m, string s){//reads each line in the inputted file, splits the file isto its individual words, takes out any non-alphabetical characters then adds the word paired with its frequency to the inputted map. Returns true if the function sucessfully opened the file or false if the file was not found
    ifstream file;
    try{
        file.open(s);//tries to open the file with the inputted name
    }
    catch(...){
        return false;//returns false if the file is not found
    }
    string str;
    while (file >> str){
        vector<string> line = split(str);//splits the line into its individual words
        for (auto c : line){
            pair<string, long> p;
            string word = clean_word(c);//takes out all non-alphabetical characters from the string
            if (m.find(word) == m.end()){
                p.first = word;
                p.second = 1;
                m.insert(p);
            }
            else{
                m[word] += 1;
            }
        }
    }
    return true;
}
ostream& print_map(ostream& out, const map_type& m){//prints every key and value seperated by commas to an ostream, returns the ostream
    long num = m.size();
    long count = 1;
    for (auto c : m){
        out << c.first << ":" << c.second;
        if (count < num){
            out << ",";
            count += 1;
        }
    }
    return out;
}
double jaccard_similarity(const map_type &m1, const map_type &m2){//counts the number of shared words in both maps then does the necessary calculation to find the similarity and returns it
    long num1 = m1.size();
    long num2 = m2.size();
    long count = 0;
    for (auto a : m1){
        for (auto b : m2){
            if (a.first == b.first){
                count += 1;
            }
        }
    }
    double denom = (num1 + num2 - count);
    double ans = count/denom;//computes the similarity
    return ans;
}
double calc_norm_factor(const map_type &m){//calculates the norm factor for a map and returns it
    long sum = 0;
    for (auto c : m){
        sum += pow(c.second, 2);
    }
    double result = pow(sum, .5);
    return result;
}
double cosine_similarity_tf(const map_type &m1, const map_type &m2){//finds cosine similarity for two maps and returns it
    double result = 0;
    double nf1 = calc_norm_factor(m1);//norm factor for the first map
    double nf2 = calc_norm_factor(m2);//norm factor for the second map
    map_type x1;
    map_type x2;
    vector<string> words = {};//used to keep track of all the words in both maps
    for (auto c : m1){
        if (find(words.begin(), words.end(), c.first) == words.end()){
            words.push_back(c.first);//adds new words to the vector
        }
    }
    for (auto c : m2){
        if (find(words.begin(), words.end(), c.first) == words.end()){
            words.push_back(c.first);//adds new words to the vector
        }
    }
    for (auto c : words){
        long num1 = 0, num2 = 0;
        for (auto p : m1){
            if (p.first == c){//tests if the word is in the first map to get the frequency, frequency is 0 if the word is not in the first map
                num1 = p.second;
                break;
            }
            else{
                num1 = 0;
            }
        }
        for (auto p : m2){
            if (p.first == c){//tests if the word is in the second map to get the frequency, frequency is 0 if the word is not in the second map
                num2 = p.second;
                break;
            }
            else{
                num2 = 0;
            }
        }
        result += ((num1 / nf1) * (num2 / nf2));//calculates the similarity using the given equation
    }
    return result;
}
