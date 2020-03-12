#include<string>
#include<numeric>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd((int)str1.length(), (int)str2.length())); // __gcd() 为c++自带的求最大公约数的函数
    }
};
