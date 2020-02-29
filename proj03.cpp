//proj03
//Nate Wood
#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
#include <cmath>
using std::sqrt; using std::pow;
bool is_prime(long x){
    cout << boolalpha;
    bool ans = true;
    for (long y = 2; y <= sqrt(x); y += 1){
        bool prime = is_prime(y);
        if (x % y == 0 && prime == true){
            ans = false;
            return ans;
        }
    }
    return ans;
} // of is_prime
bool is_powerful(long x){
    cout << boolalpha;
    bool ans = false;
    for (long y = 2; y < (x/2); y++){
        cout << "start of loop" << endl;
        if (x % y == 0){
            cout << "yes1" << endl;
            long squared = y * y;
            bool prime = is_prime(y);
            if (x % squared != 0 && prime == true){
                cout << "no" << endl;
                ans = false;
                return ans;
            }
            else if (x % squared == 0 && prime == true){
                cout << "yes2" << endl;
                ans = true;
            }
        }
    }
    return ans;
} // of is_powerful
bool is_perfect_power(long x){
    cout << boolalpha;
    bool ans = false;
    for (long y = 2; y <= x; y++){
        for (long n = 2; n <= (x/2); n++){
            if (pow(y, n) == x){
                ans = true;
                return ans;
            }
            else if (pow(y, n) > x){
                break;
            }
        }
    }
    return ans;
} // of is_perfect_power
bool is_achilles(long x){
    cout << boolalpha;
    bool ans = false;
    bool prime = is_prime(x);
    if (prime == false){
        bool powerful = is_powerful(x);
        cout << powerful << endl;
        bool perfect = is_perfect_power(x);
        cout << perfect << endl;
        if (powerful == true && perfect == false){
            ans = true;
            return ans;
        }
    }
    return ans;
} // of is_achilles

int main (){
    cout << boolalpha;
    int test_case;
    cout << "case: " << endl;
    cin >> test_case;
    
    switch (test_case){
            
            
        case 1 : {
            long num;
            cout << "num: " << endl;
            cin >> num;
            cout <<  is_prime(num) << endl;
            break;
        } // of case 1
            
        case 2 : {
            long num;
            cout << "num: " << endl;
            cin >> num;
            cout << is_powerful(num) << endl;
            break;
        } // of case 2
            
        case 3 : {
            long num;
            cout << "num: " << endl;
            cin >> num;
            cout << is_perfect_power(num) << endl;
            break;
        } // of case 3
            
        case 4 : {
            long num;
            cout << "num: " << endl;
            cin >> num;
            cout << is_achilles(num) << endl;
            break;
        } // of case 4
            
    } // of switch
} // of main
