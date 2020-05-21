# include<string>

using namespace std;

class Solution {
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
