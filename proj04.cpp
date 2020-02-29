//proj04
//Nate Wood

// whatever includes you need
#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<cctype>
using std::isdigit; using std::isalpha; using std::isxdigit;

// your functions here
bool valid_hex(string in){
    bool ans = true;
    if (string{in[0]} == "-"){
        string prefix = in.substr(1, 2);
        if (prefix == "0x"){
            for (int i = 3; i < in.length(); ++i){
                if (isxdigit(in[i]) == false){
                    ans = false;
                    break;
                }
            }
        }
        else{
            ans = false;
            return ans;
        }
    }
    else{
        string prefix = in.substr(0, 2);
        if (prefix == "0x"){
            for (int i = 2; i < in.length(); ++i){
                cout << in[i] << endl;
                if (isxdigit(in[i])){
                    ans = true;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        else{
            ans = false;
            return ans;
        }
    }
    return ans;
}
bool valid_octal(string in){
    bool ans = true;
    if (string{in[0]} == "-"){
        string prefix = in.substr(1, 1);
        if (prefix == "0"){
            for (int i = 2; i < in.length(); ++i){
                if (string{in[i]} >= "8"){
                    ans = false;
                    break;
                }
            }
        }
        else{
            ans = false;
            return ans;
        }
    }
    else {
        string prefix = in.substr(0, 1);
        if (prefix == "0"){
            for (int i = 1; i < in.length(); ++i){
                if (string{in[i]} >= "8"){
                    ans = false;
                    break;
                }
            }
        }
        else{
            ans = false;
            return ans;
        }
    }
    return ans;
}
bool valid_binary(string in){
    bool ans = true;
    if (string{in[0]} == "-"){
        string prefix = in.substr(1, 2);
        if (prefix == "0b"){
            for (int i = 3; i < in.length(); ++i){
                if (string{in[i]} != "1" && string{in[i]} != "0"){
                    ans = false;
                    break;
                }
            }
        }
        else{
            ans = false;
            return ans;
        }
    }
    else{
        string prefix = in.substr(0, 2);
        if (prefix == "0b"){
            for (int i = 2; i < in.length(); ++i){
                if (string{in[i]} != "1" && string{in[i]} != "0"){
                    ans = false;
                    break;
                }
            }
        }
        else{
            ans = false;
            return ans;
        }
    }
    return ans;
}
bool valid_int(string in){
    bool ans = true;
    if (string{in[0]} == "-"){
        for (int i = 1; i < in.length(); ++i){
            if (isdigit(in[i]) == false){
                ans = false;
                break;
            }
        }
    }
    else{
        for (int i = 0; i < in.length(); ++i){
            if (isdigit(in[i]) == false){
                ans = false;
                return ans;
            }
        }
    }
    return ans;
}
bool valid_float(string in){
    int e_count = 0;
    int period_count = 0;
    bool ans = true;
    if (string{in[0]} == "-"){
        for (int i = 1; i < in.length(); ++i){
            if (isdigit(in[i]) == false){
                if (string{in[i]} == "e"){
                    e_count += 1;
                }
                else if (string{in[i]} == "."){
                    period_count += 1;
                }
                else{
                    ans = false;
                    return ans;
                }
            }
        }
    }
    else{
        for (int i = 0; i < in.length(); ++i){
            if (isdigit(in[i]) == false){
                if (string{in[i]} == "e"){
                    e_count += 1;
                }
                else if (string{in[i]} == "."){
                    period_count += 1;
                }
                else{
                    ans = false;
                    return ans;
                }
            }
        }
    }
    if (e_count > 1 or period_count > 1){
        ans = false;
    }
    else if (e_count == 0 and period_count ==0)
        ans = false;
    return ans;
}
string classify_string(string in){
    if (valid_hex(in) == true){
        return "hexadecimal";
    }
    else if (valid_octal(in) == true){
        return "octal";
    }
    else if (valid_binary(in) == true){
        return "binary";
    }
    else if (valid_int(in) == true){
        return "integer";
    }
    else if (valid_float(in) == true){
        return "float";
    }
    else{
        return "false";
    }
}

int main (){
    cout << boolalpha;
    int testnum;
    cout << "Enter a test case: " << endl;
    cin >> testnum;
    
    switch (testnum) {
        case 1 : {
            string to_test;
            cout << "Enter a number: " << endl;
            cin >> to_test;
            cout << valid_hex(to_test) << endl;
            break;
        }
            
        case 2:{
            string to_test;
            cout << "Enter a number: " << endl;
            cin >> to_test;
            cout << valid_octal(to_test) << endl;
            break;
        }
            
        case 3:{
            string to_test;
            cout << "Enter a number: " << endl;
            cin >> to_test;
            cout << valid_binary(to_test) << endl;
            break;
        }
            
        case 4:{
            string to_test;
            cout << "Enter a number: " << endl;
            cin >> to_test;
            cout << valid_float(to_test) << endl;
            break;
        }
            
        case 5:{
            string to_test;
            cout << "Enter a number: " << endl;
            cin >> to_test;
            cout << valid_int(to_test) << endl;
            break;
        }
            
        case 6:{
            string to_test;
            cout << "Enter a number: " << endl;
            cin >> to_test;
            cout << classify_string(to_test) << endl;
            break;
        }
            
            
    }// of switch
}// of main
