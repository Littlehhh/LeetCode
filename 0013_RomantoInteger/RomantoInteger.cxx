#include<string>
#include<unordered_map>
using namespace std;

unordered_map<string, int> lookup = {
    {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},
    {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
};
class Solution {
public:
    int romanToInt(string s) {
        auto cur = s.begin();
        int ans = 0;
        while(cur != s.end()){
            if( cur+1 != s.end() && lookup.find(string(cur, cur+2)) != lookup.end()){
                ans += lookup[string(cur, cur+2)];cur+=2;
            }
            else{
                ans += lookup[ string(cur, cur+1) ];
                ++cur;
            }
        }
        return ans;
    }
};