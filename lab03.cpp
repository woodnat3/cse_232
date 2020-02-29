//lab03
//Nate Wood

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::fixed;
#include <cmath>
using std::pow; using std::abs;
#include <iomanip>
using std::setprecision;
double fn(double x){
    double ans = -6.0 * pow(x, 2.0) + 5.0 * x + 3.0;
    return ans;
}
double integral(double x){
    double a = -2.0 * x;
    double b = 2.5 * x;
    double c = 3.0 * x;
    double ans = a + b + c;
    return (double)ans;
}
double trapezoid(double a, double b, long n){
    double diff = (b-a)/n;
    double sub = a;
    double sum = 0;
    for (long y=0; y < n; ++y){
        double top = sub + diff;
        double y1 = fn(sub);
        double y2 = fn(top);
        double area = ((top - sub) * (y1 + y2))/2.0;
        sum += area;
        sub += diff;
    }
    return sum;
}
int main(){
    cout << fixed << setprecision(6);
    double tolerance;
    cout << "Tolerance: ";
    cin >> tolerance;
    cout << endl;
    long guess;
    cout << "Initial trapezoid count: ";
    cin >> guess;
    cout << endl;
    long n  = guess;
    long i = true;
    while (i == true){
        double reala = integral(0);
        double realb = integral(1);
        double real = realb - reala;
        double est = trapezoid(0, 1, n);
        double diff = abs(real - est);
        if (diff <= tolerance){
            cout << n << " " << est << " " << real << " " << tolerance << endl;
            i = false;
            return 0;
        }
        else{
            cout << "Result:" << est << ", traps:" << n << ", diff:" << diff << endl;
            n *= 2;
        }
    }
}
