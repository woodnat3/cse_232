//Nate Wood
#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;


#include "proj05_functions.h"

int main (){
    cout << boolalpha;
    int testnum;
    cout << "test: ";
    cin >> testnum;
    
    switch (testnum){
            
        case 1: {
            string s;
            cout << "s: ";
            getline(cin,s);
            cout << lower_case(s)  <<endl;
            break;
        }
            
        case 2: {
            char c;
            cout << "c: ";
            cin >> c;
            cout << to_binary(c) <<endl;
            break;
        }
            
        case 3:{
            string n;
            cout << "n: ";
            cin >> n;
            cout << from_binary(n) << endl;
            break;
        }
            
        case 4: {
            string plain, secret;
            plain = "This is a test of the emergency broadcast system.";
            secret = "help me";
//            cout << "plain: ";
//            getline(cin, plain);
//            cout << "secret: ";
//            getline(cin,secret);
            cout << check_message(plain, secret) << endl;
            break;
        }
            
        case 5: {
            string plain, secret;
            plain = "well... this is awkward, sorry about that!";
            secret = "run";
//            cout << "plain: ";
//            getline(cin, plain);
//            cout << "secret: ";
//            getline(cin,secret);
            cout << encode(plain, secret) << endl;
            break;
        }
            
        case 6: {
            string encoded;
            encoded = "Ok coOL tHats OK i Guess";
//            cout << "encoded: ";
//            getline(cin, encoded);
            cout << decode(encoded) << endl;
            break;
        }
            
    }// of switch
} // of main
