//Nate Wood
#include "proj08-struct.h"
#include<iostream>
using std::cout; using std::endl; using std::skipws;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<fstream>
using std::ifstream; using std::ofstream;
#include<vector>
using std::vector;
#include<typeinfo>
#include<stdexcept>
using std::invalid_argument;
Image::Image (string f_name){
    cout << skipws;
    ifstream file;
    file.open(f_name);
    string x;
    int count = 0;
    while (getline(file, x)){
        //cout << x << endl;
//        if (x != "P2" && x[0] != '#'){
//
//        }
        if (isdigit(x[0]) && x[0] != '#'){
            if (count == 0){
                vector<long> dimensions = {};
                string num1;
                for (auto c : x){
                    if (c != ' '){
                        num1 += c;
                    }
                    else{
                        try{
                            dimensions.push_back(stol(num1));
                        }
                        catch(invalid_argument){
                            //cout << "one" << endl;
                        }
                        num1 = "";
                    }
                }
                try{
                    dimensions.push_back(stol(num1));
                }
                catch(invalid_argument){
                    //cout << "two" << endl;
                }
                width_ = dimensions[0];
                //cout << width_ << endl;
                height_ = dimensions[1];
                //cout << height_ << endl;
                count += 1;
            }
            else if (count == 1){
                try{
                    max_val_ = stol(x);
                }
                catch(invalid_argument){
                    //cout << "three" << endl;
                }
                //cout << max_val_ << endl;
                count += 1;
            }
            else if (count > 1){
                vector<long> line = {};
                string num2 = "";
                for (auto c : x){
                    if (iswspace(c) == false or c != '\n'){
                        num2 += c;
                    }
                    else{
                        try{
                            cout << num2 << endl;
                            line.push_back(stol(num2));
                        }
                        catch(invalid_argument){
                            num2 = num2;
                        }
                        //cout << "here?" << endl;
                        num2 = "";
                    }
                }
                pixels_.push_back(line);
                count += 1;
            }
        }
    }
    file.close();
}
void Image::write_image(string f_name) const{
    //cout << "write" << endl;
    ofstream file (f_name);
    file << "P2" << endl;
    //cout << "P2" << endl;
    file << width_ << " " << height_ << endl;
    //cout << width_ << " " << height_ << endl;
    file << max_val_ << endl;
    //cout << max_val_ << endl;
    for (auto list : pixels_){
        for (auto c : list){
            file << c << " ";
            //cout << c << " ";
        }
        file << endl;
        //cout << endl;
    }
    file.close();
}
Image Image::convolve(vector<vector<long>> mask, long div, long whiten) const{
    Image result;
    long edge = width_-1;
    result.max_val_ = max_val_;
    result.width_ = width_;
    result.height_ = height_;
    for ( int y = 0; y < height_; y++){
        vector<long> line;
        for (int x = 0; x < width_; x++){
            if (y == 0){
                if (x == 0){
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else if (x == edge){
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x-1]*mask[1][0] + pixels_[y+1][x-1]*mask[2][0] + pixels_[y+1][x]*mask[2][1];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else{
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1] + pixels_[y+1][x-1]*mask[2][0] + pixels_[y][x-1]*mask[1][0];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
            }
            else if (x == height_-1){
                if (x == 0){
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else if (x == edge){
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x-1]*mask[1][0] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y-1][x]*mask[0][1];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else{
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y][x-1]*mask[1][0];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
            }
            else{
                if (x == 0){
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else if (x == edge){
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x-1]*mask[1][0] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y-1][x]*mask[0][1] + pixels_[y+1][x-1]*mask[2][0] + pixels_[y+1][x]*mask[2][1];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else{
                    long num = pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y][x-1]*mask[1][0] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1] + pixels_[y+1][x-1]*mask[2][0];
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else{
                        line.push_back(num);
                    }
                }
            }
        }
        result.pixels_.push_back(line);
    }
    return result;
}
Image Image::sharpen() const{
    vector<vector<long>> mask = {{0, -1, 0},{-1, 5, -1},{0, -1, 0}};
    Image result = convolve(mask);
    return result;
}
Image Image::edge_detect() const{
    vector<vector<long>> mask = {{0, 1, 0},{1, -4, 1},{0, 1, 0}};
    Image result = convolve(mask, 1, 50);
    return result;
}
Image Image::blur() const{
    vector<vector<long>> mask = {{1, 1, 1},{1, 1, 1},{1, 1, 1}};
    Image result = convolve(mask, 9, 0);
    return result;
}
Image Image::emboss() const{
    vector<vector<long>> mask = {{-2, -1, 0},{-1, 1, 1},{0, 1, 2}};
    Image result = convolve(mask);
    return result;
}
void Image::embed(const Image & secret){
    convolve(secret.pixels_);
}
Image Image::extract(long max_val) const{
    Image result;
    result.max_val_ = max_val;
    result.width_ = width_;
    result.height_ = height_;
    for (auto x : pixels_){
        vector<long> line;
        for (auto c : x){
            if (c > max_val){
                line.push_back(max_val);
            }
            else{
                line.push_back(0);
            }
        }
        result.pixels_.push_back(line);
    }
    return result;
}
