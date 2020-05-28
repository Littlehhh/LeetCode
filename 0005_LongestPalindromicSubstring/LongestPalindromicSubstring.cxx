#include<string>
#include<vector>

using namespace std;

class Solution1 {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if( !len ) return "";
        int MaxSubLen=0;
        std::string substring;
        for( int i=0; i < len; ++i ){
            // Odd condition
            int OddLen = getPalindromeLenByExpandCenter(s, i, i);
            // even condition
            int EvenLen = getPalindromeLenByExpandCenter(s, i, i+1);     
            int SubLen = std::max(OddLen, EvenLen);
            if(SubLen > MaxSubLen){
                substring = s.substr(i - (SubLen - 1) / 2 , SubLen ); 
                MaxSubLen = SubLen;
            }
        }
        return substring;
    }
    int getPalindromeLenByExpandCenter(string &s, int lo, int hi){
        while( lo >= 0 && hi < s.size() && s[lo] == s[hi]){
                --lo;++hi;
        }
        return hi-lo-1;
    }
};


class Solution {
public:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }

    string longestPalindrome(string s) {
        int start = 0, end = -1;
        string t = "#";
        for (char c: s) {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;

        vector<int> arm_len;
        int right = -1, j = -1;
        for (int i = 0; i < s.size(); ++i) {
            int cur_arm_len;
            if (right >= i) {
                int i_sym = j * 2 - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            }
            else {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right) {
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start) {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        string ans;
        for (int i = start; i <= end; ++i) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }
        return ans;
    }
};

