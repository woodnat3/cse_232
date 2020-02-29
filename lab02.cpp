//lab02
//Nate Wood

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <cmath>
using std::pow;
int main(){
    long num;
    long count = 0;
    long boolean1 = true;
    cout << "Enter a number: " << endl;
    cin >> num;
    while (boolean1 == true){
        if (num <= 0){
            cout << "Error" << endl;
            boolean1 = false;
            return 0;
        }
        else if (num > 0 && num < 10){
            cout << count << " " << num << endl;
            boolean1 = false;
            return 0;
        }
        else{
            count += 1;
            long boolean2 = true;
            long digit = 1;
            long div1 = 10;
            while (boolean2){
                if (num % div1 == num){
                    boolean2 = false;
                }
                else if (num % div1 == 0){
                    cout << count << " " << 1 << endl;
                    boolean1 = false;
                    return 0;
                }
                else{
                    digit += 1;
                    div1 *= 10;
                }
            }
            long power = digit - 1;
            long sum = 0;
            for (long a = 0; a < digit; ++a){
                long new1 = (long)num % ((long)pow((long)10, (long)power));
                long new_num = ((num - new1)/(pow(10, power)));
                power -= 1;
                sum += new_num;
                num = new1;
            }
            num = sum;
        }
    }
}
