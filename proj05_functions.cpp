//Nate Wood
#include "proj05_functions.h"
#include<iostream>
using std::cout; using std::skipws; using std::endl;
#include<string>
#include<cmath>
using std::pow;

string lower_case(const string& s){ //takes all alphabetical characters in a string and makes them lowercase
    cout << skipws;
    string result = "";//string after making characters lowercase
    for (auto c : s){
        if (c != ' ')
            c = tolower(c);
        result += c;
    }
    return result;
}
string to_binary(char c){//turns a character into a five character binary based on the index of the letter in the alphabet
    string result = "";//string of the 5 character binary
    if (isalpha(c) == false){//if the character is not a letter an empty string is returned
        return result;
    }
    else{
        if (isupper(c)){
            return result;
        }
        else{
            int index = c - 'a';//finds the index of the letter
            for (int i = 4; i >= 0; i--){
                if (index >= pow(2, i)){
                    index -= pow(2, i);
                    result += "1";
                }
                else{
                    result += "0";
                }
            }
            return result;
        }
    }
}
char from_binary(const string& bit_str){//takes a 5 character binary and finds the ltter associated with the index
    int num = 0;
    for (int i = 4; i >= 0; i--){//adds up all of the binary characters to get the index of the letter
        if (bit_str[4-i] == '1'){
            num += pow(2, i);
        }
    }
    char c = static_cast<char>(num + 97);//turns the index of the letter into the letter, returns 0 if the character is not a letter
    if (isalpha(c))
        return c;
    else
        return 0;
}
bool check_message(const string& plaintext, const string& message){//checks to make sure the binary of the secret messgage can fit in the plaintext
    cout << skipws;
    int num1 = 0;
    for (auto c : plaintext){//finds the amount of letters in the plaintext
        if (isalpha(c)){
            num1 += 1;
        }
    }
    int num2 = 0;
    for (auto c : message){//finds the amount of letters in the secret message and adds 5 for each because the binary would be 5 times the length
        if (isalpha(c)){
            num2 += 5;
        }
    }
    if (num1 >= num2){//returns a boolean based on if the message would fit in the plaintext
        return true;
    }
    else{
        return false;
    }
}
string encode(const string& plaintext, const string& message){//encodes a message by capitalizing each letter that would have to same index as a 1 in the binary secret message
    cout << skipws;
    string new1 = lower_case(plaintext);
    string new2 = lower_case(message);
    bool ans = check_message(new1, new2);
    if (ans == false){//tests if the encoding would be possible, returns "Error" if it is not
        return "Error";
    }
    else{
        string binary = "";
        for (auto c : message){//turns the secret message into a binary
            if (isalpha(c)){
                binary += to_binary(c);
            }
            else
                binary += c;
        }
        int index = 0;
        for (int i = 0; i < binary.length(); i++){//capitalizes each letter corresponding with a 1 in the binary message
            bool test = true;
            while (test){
                if (isalpha(new1[index]) == false){
                    index += 1;
                }
                else{
                    test = false;
                }
            }
            if (binary[i] == '1'){
                new1[index] = toupper(new1[index]);
            }
            index += 1;
        }
        return new1;
    }
}
string decode(const string& to_decode){//takes a plaintext and decodes the message by finding the capital letters and making a binary code from them to decode
    string message = "";
    string binary = "";
    int num = 0;
    for (auto c : to_decode){//finds the number of letters in the string
        if (isalpha(c)){
            num += 1;
        }
    }
    int remainder = num % 5;//finds the amount of letters that can not be a part of a binary if the number of letters is not divisible by 5
    int count = num - remainder;//makes the count by subtracting the number of remaining letters from the total number of letters
    int index = 0;
    for (int i = 0; i < count; i++){
        if (isalpha(to_decode[index]) == false){//tests if the character is a letter, if not then the character is skipped
            index += 1;
        }
        if (isupper(to_decode[index])){//tests for capital letters to add 1's to the binary, if they are not capital a 0 is added instead
            binary += "1";
        }
        else{
            binary += "0";
        }
        index += 1;
    }
    for (int i = 0; i < (count/5); i++){//decodes the binary by splitting it into segments of 5 characters and calculating the total of each to get the index of each letter
        int total = 0;
        string sub = binary.substr(i*5, 5);//splits the binary into segments of 5 characters
        int power = 4;
        for (auto c : sub){
            if (c == '1'){
                total += pow(2, power);
            }
            power -= 1;
        }
        message += static_cast<char>(total + 97);//adds the letters to the message once decoded from the binary
    }
    return message;
}
