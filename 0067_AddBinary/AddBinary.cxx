#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) return addBinary(b, a);
        if(a.size() == 0 ) return b;
        if(b.size() == 0 ) return a;
        auto a_it = a.rbegin();
        auto b_it = b.rbegin();
        int carry = 0;
        while(b_it != b.rend()){
            int sum = *a_it-'0' + *b_it - '0' + carry;
            *a_it = sum % 2 + '0';
            carry = sum / 2;
            ++a_it;++b_it;
        }
        while(a_it != a.rend()){
            int sum = *a_it- '0' + carry;
            *a_it = sum % 2 + '0';
            carry = sum / 2;
            ++a_it;
        }
        if(carry) a.insert(a.begin(), '1');
        return a;
    }
};