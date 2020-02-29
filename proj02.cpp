//proj02.cpp
//Nate Wood

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <cmath>
using std::pow; using std::sqrt; using std::floor;

int main(){
    long low;
    cout << "Enter a low value: " << endl;
    cin >> low;
    long high;
    cout << "Enter a high value: " << endl;
    cin >> high;
    if (low > high){
        cout << "Error" << endl;
        return 0;
    }
    long highest = 0;
    long num1 = 0;
    long longest = 0;
    long num2 = 0;
    for (long a = high; a >= low; a -= 1){
        cout << "here" << endl;
        long count = 0;
        long sub = a;
        while (sub != 1.0){
            count += 1;
            if (sub % 2 == 0){
                cout << "even" << endl;
                sub = floor(sqrt(sub));
                cout << sub << endl;
                if (sub > highest){
                    highest = sub;
                    num1 = a;
                }
            }
            else{
                cout << "odd" << endl;
                sub = floor(pow(sub, 1.5));
                cout << sub << endl;
                if (sub > highest){
                    highest = sub;
                    num1 = a;
                }
            }
        }
        if (count > longest){
            longest = count;
            num2 = a;
        }
    }
    cout << num2 << " " << longest << endl;
    cout << num1 << " " << highest << endl;
}
