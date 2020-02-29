//lab04
//Nate Wood

#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string;
#include<cmath>
using std::pow;
// note you need algorithm and sort
#include<algorithm>
using std::sort;

#include<cctype>

long loc_to_dec(string loc){
    long ans = 0;
    for (int i = 0; i < loc.length(); ++i){
        char letter = loc[i];
        long num = static_cast<int>(letter) - 97;
        ans += pow(2, num);
    }
    return ans;
}
string abbreviate(string loc){
    bool go = true;
    while (go == true){
        sort(loc.begin(), loc.end());
        char last = loc[0];
        go = false;
        for (int i = 1; i < loc.length(); ++i){
            char letter = loc[i];
            if (letter == last){
                go = true;
                int num = static_cast<int>(letter);
                letter = static_cast<char>(num + 1);
                loc[i] = letter;
                loc.erase(i-1, 1);
                sort(loc.begin(), loc.end());
                continue;
            }
            last = letter;
        }
    }
    return loc;
}
string dec_to_loc(long dec){
    string loc = "";
    while (dec > 0){
        for (long i = 25; i >= 0; --i){
            if (pow(2, i) <= dec){
                dec -= pow(2, i);
                loc += static_cast<char>(i + 97);
            }
        }
    }
    loc = abbreviate(loc);
    sort(loc.begin(), loc.end());
    return loc;
}
long add_loc(string loc1, string loc2){
    string loc = loc1 + loc2;
    loc = abbreviate(loc);
    return loc_to_dec(loc);
 }
int main(){
    string loc;
    cout << "Enter a string: " << endl;
    cin >> loc;
    long dec;
    cout << "Enter a number: " << endl;
    cin >> dec;
    cout << loc_to_dec(loc) << " " << abbreviate(loc) << " " << dec_to_loc(dec) << " " << add_loc(loc, loc) << endl;
}
