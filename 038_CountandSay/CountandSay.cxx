#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return string();
        if( n == 1) return "1";
        string pre_s = "1";
        while(--n){
            char pre = *pre_s.begin();
            int count = 0;
            string ans;
            for(auto && ch:pre_s){
                if(ch == pre){
                    ++count;
                }
                else{
                    ans += to_string(count);
                    ans += pre;
                    pre = ch;
                    count = 1;
                }
            }
            if(count > 0) {
                ans += to_string(count);
                ans += pre;
            }
            // cout << ans << endl;
            pre_s = ans;
        }
        return pre_s;
    }
};

// Recursion
class Solution2 {
public:
    string countAndSay(int n) {
        if(n == 0) return string();
        if( n == 1) return "1";
        string pre_s = countAndSay(n-1);
            char pre = *pre_s.begin();
            int count = 0;
            string ans;
            for(auto && ch:pre_s){
                if(ch == pre){
                    ++count;
                }
                else{
                    ans += to_string(count);
                    ans += pre;
                    pre = ch;
                    count = 1;
                }
            }
            if(count > 0) {
                ans += to_string(count);
                ans += pre;
            }
            // cout << ans << endl;
            pre_s = ans;
        
        return pre_s;
    }
};