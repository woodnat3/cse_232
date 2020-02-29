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
Image::Image (string f_name){//constructor for an image when given a file name, extracts info from file to make image object
    cout << skipws;
    ifstream file;
    file.open(f_name);
    string x;
    while (getline(file, x)){//gets each line from the file
        int space_count = 0;//counts spaces to determine what kind of info is in the line
        int pound_count = 0;
        //cout << x << endl;
        //        if (x != "P2" && x[0] != '#'){
        //
        //        }
        for (auto c : x){
            if (c == ' '){
                space_count += 1;
            }
            else if (c == '#'){
                pound_count += 1;
            }
        }
        if (isdigit(x[0]) and pound_count == 0){
            //cout << x << endl;
            if (space_count == 1){
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
                        catch(invalid_argument& e){
                            continue;
                        }
                        num1 = "";
                    }
                }
                try{
                    dimensions.push_back(stol(num1));
                }
                catch(invalid_argument& e){
                    continue;
                }
                width_ = dimensions[0];// sets width of the image
                //cout << width_ << endl;
                height_ = dimensions[1];//sets height of the image
                //cout << height_ << endl;
            }
            else if (space_count == 0){
                try{
                    max_val_ = stol(x);// sets max_val of the image
                }
                catch(invalid_argument& e){
                    continue;
                }
                //cout << max_val_ << endl;
            }
            else if (space_count > 1){
                vector<long> line = {};
                string num2 = "";
                for (auto c : x){
                    if (c != ' ' and iswspace(c) == false){
                        num2 += c;
                    }
                    else{
                        if (num2.empty()){
                            continue;
                        }
                        else{
                            line.push_back(stol(num2));//adds each element to a vector
                        }
                        num2 = "";
                    }
                }
                if (num2.empty()){
                    line = line;
                }
                else{
                    line.push_back(stol(num2));
                }
                pixels_.push_back(line);// each filled vector is then added to the pixels of the image
            }
            else{
                //cout << x << endl;
            }
        }
    }
    file.close();
}
void Image::write_image(string f_name) const{//writes an image to a .pgm file
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
Image Image::convolve(vector<vector<long>> mask, long div, long whiten) const{//
    Image result;
    long edge = width_-1;
    result.max_val_ = max_val_;
    result.width_ = width_;
    result.height_ = height_;
    for ( int y = 0; y < height_; y++){
        vector<long> line;
        for (int x = 0; x < width_; x++){
            //cout << x << " " << y << endl;
            if (y == 0){//if top of image
                if (x == 0){//if far left of image
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else if (x == edge){//if far right of image
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x-1]*mask[1][0] + pixels_[y+1][x-1]*mask[2][0] + pixels_[y+1][x]*mask[2][1]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else{//anywhere else
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1] + pixels_[y+1][x-1]*mask[2][0] + pixels_[y][x-1]*mask[1][0]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
            }
            else if (y == height_-1){//if bottom of image
                if (x == 0){//if far left of image
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else if (x == edge){//if far right of image
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x-1]*mask[1][0] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y-1][x]*mask[0][1]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else{//anywhere else
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y][x-1]*mask[1][0]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
            }
            else{//anywhere else
                if (x == 0){//if far left of image
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else if (x == edge){//if far right of image
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x-1]*mask[1][0] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y-1][x]*mask[0][1] + pixels_[y+1][x-1]*mask[2][0] + pixels_[y+1][x]*mask[2][1]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
                else{//anywhere else
                    long num = (pixels_[y][x]*mask[1][1] + pixels_[y][x+1]*mask[1][2] + pixels_[y-1][x+1]*mask[0][2] + pixels_[y-1][x]*mask[0][1] + pixels_[y-1][x-1]*mask[0][0] + pixels_[y][x-1]*mask[1][0] + pixels_[y+1][x+1]*mask[2][2] + pixels_[y+1][x]*mask[2][1] + pixels_[y+1][x-1]*mask[2][0]+whiten)/div;
                    if (num > max_val_){
                        line.push_back(max_val_);
                    }
                    else if (num < 0){
                        line.push_back(0);
                    }
                    else{
                        line.push_back(num);
                    }
                }
            }
        }
        result.pixels_.push_back(line);// each new vector with all modified pixels is added to the pixels of the resulting image
    }
    return result;
}
Image Image::sharpen() const{//applies a specific mask to the image
    Image temp;
    temp.width_ = width_; temp.height_ = height_; temp.max_val_ = max_val_; temp.pixels_ = pixels_;
    vector<vector<long>> mask = {{0, -1, 0},{-1, 5, -1},{0, -1, 0}};
    Image result = temp.convolve(mask);
    return result;
}
Image Image::edge_detect() const{//applies a specific mask to the image
    Image temp;
    temp.width_ = width_; temp.height_ = height_; temp.max_val_ = max_val_; temp.pixels_ = pixels_;
    vector<vector<long>> mask = {{0, 1, 0},{1, -4, 1},{0, 1, 0}};
    Image result = temp.convolve(mask, 1, 50);
    return result;
}
Image Image::blur() const{//applies a specific mask to the image
    Image temp;
    temp.width_ = width_; temp.height_ = height_; temp.max_val_ = max_val_; temp.pixels_ = pixels_;
    vector<vector<long>> mask = {{1, 1, 1},{1, 1, 1},{1, 1, 1}};
    Image result = temp.convolve(mask, 9, 0);
    return result;
}
Image Image::emboss() const{//applies a specific mask to the image
    Image temp;
    temp.width_ = width_; temp.height_ = height_; temp.max_val_ = max_val_; temp.pixels_ = pixels_;
    vector<vector<long>> mask = {{-2, -1, 0},{-1, 1, 1},{0, 1, 2}};
    Image result = temp.convolve(mask);
    return result;
}
void Image::embed(const Image & secret){//embeds a secret message in an image by modifying values
    for (int y = 0; y < secret.height_; y++){
        for (int x = 0; x < secret.width_; x++){
            if (secret.pixels_[y][x] == 0){
                if (pixels_[y][x] % 2 == 0){
                    continue;
                }
                else{
                    pixels_[y][x] -= 1;
                }
            }
            else{
                if (pixels_[y][x] % 2 == 0){
                    if (pixels_[y][x] == max_val_){
                        pixels_[y][x] -= 1;
                    }
                    else{
                        pixels_[y][x] += 1;
                    }
                }
            }
        }
    }
}
Image Image::extract(long max_val) const{//extracts a secret image based on the parity of the elements of the plain image
    Image result;
    result.max_val_ = max_val;
    result.width_ = width_;
    result.height_ = height_;
    for (auto x : pixels_){
        vector<long> line;
        for (auto c : x){
            //cout << c << " ";
            if (c % 2 != 0){
                line.push_back(result.max_val_);
            }
            else{
                line.push_back(0);
            }
        }
        //cout << endl;
        result.pixels_.push_back(line);
    }
    cout << "result" << endl;
//    for (auto x : result.pixels_){
//        for (auto c : x){
//            cout << c << " ";
//        }
//        cout << endl;
//    }
    return result;
}
