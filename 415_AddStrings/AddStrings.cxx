#include<string>

using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size()) return addStrings(num2, num1);
        if(num1 == "0") return num2;
        if(num2 == "0") return num1;
        string ans;
        auto && it1 = num1.rbegin(), &&it2 = num2.rbegin();
        int carry = 0;
        while(it2!=num2.rend() ){
            int sum = *it1-'0' + *it2 - '0'+carry;
            ans.push_back(sum%10+'0');
            carry = sum / 10;
            ++it1;
            ++it2;
        }
        while(it1!= num1.rend()){
            int sum = *it1-'0'+carry;
            ans.push_back(sum%10+'0');
            carry = sum / 10;
            ++it1;
        }
        if(carry) ans.push_back(carry+'0');
        return string(ans.rbegin(), ans.rend());
    }
};