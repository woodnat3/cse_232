//Nate Wood

#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include <string>
using std::string;

#include "proj10_class.h"

int main (){
//    MVM<string,long> mvm1;
//
//    size_t size = 0;
//    size_t num_elements = 0;
//    cout << mvm1.size() << " " << size << endl;
//    cout << mvm1.num_elements_ << " " << num_elements << endl;
//
//    mvm1.add("tuv", 2);
//
//    size = 1;
//    num_elements = 2;
//    cout << mvm1.size() << " " << size << endl;;
//    cout << mvm1.num_elements_ << " " << num_elements << endl;
//
//    mvm1.add("abc", 3);
//    mvm1.add("tuv", 4);
//
//    size = 2;
//    num_elements = 2;
//    cout << mvm1.size() << " " << size << endl;
//    cout << mvm1.num_elements_ << " " << num_elements << endl;;
//
//    mvm1.add("xyz", 5);
//
//    size = 3;
//    num_elements = 4;
//    cout << mvm1.size() << " " << size << endl;
//    cout << mvm1.num_elements_ << " " << num_elements << endl;
    cout << boolalpha;
    Element<string, string> e1;
    e1.key_ = "abc";
    e1.values_[0] = "a";
    e1.values_[1] = "b";
    e1.values_[2] = "c";
    e1.count_ = 3;
    cout << e1 << endl;
    Element<string, string> e2("abc", {"a", "b", "c"} );
    cout << (e1 == e2) << endl;

    MVM<string, string> mvm1 { {"abc", {"a","b", "c"}},{"xyz", {"x","y","z"}}};
    cout << "mvm " <<  mvm1 << endl;
    auto result = mvm1.find_key("abc");
    cout << result->key_ << endl;
    string * result_key = nullptr;
    size_t size_result_key = mvm1.find_value("a", result_key);
    copy(result_key, result_key + size_result_key, ostream_iterator<string>(cout, ",") );
    cout <<"\n"<<mvm1.size() << endl;
    delete [] result_key;
    result_key = nullptr;
    cout << mvm1.add("qrs", "q") << endl;
    cout << mvm1.add("bcd", "a") << endl;
    cout << mvm1.add("qrs", "a") << endl;
    cout << mvm1 << endl;
    size_result_key = mvm1.find_value("a", result_key);
    copy(result_key, result_key + size_result_key, ostream_iterator<string>(cout, ",") );
//    cout <<"\n"<< mvm1.remove_key("bcd") << endl;
    delete [] result_key;
    result_key = nullptr;
//    cout << mvm1 << endl;
    size_result_key = mvm1.remove_value("a", result_key);
    copy(result_key, result_key + size_result_key, ostream_iterator<string>(cout, ",") );
    cout << "here" << endl;
    cout << "\n" << mvm1 << endl;
    delete [] result_key;
    result_key = nullptr;
}
