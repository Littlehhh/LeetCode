#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> lookup;
        int ans = 0;
        for( auto && ch : s){
            lookup[ch]++;
            if(lookup[ch] % 2 == 0){
                ans+=2;
            }
        }
        if(ans < s.size()) ans++;
        return ans;
    }
};