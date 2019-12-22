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
            int OddLen, lo = i,  hi = i;
            while( lo >= 0 && hi < len && s[lo] == s[hi]){
                --lo;++hi;
            }
            OddLen = hi-lo-1;
            
            // even condition
            int EvenLen;     
            lo = i, hi = i+1;
            while( lo >= 0 && hi < len && s[lo] == s[hi]){
                --lo;++hi;
            }
            EvenLen = hi-lo-1;   
                
            int SubLen = std::max(OddLen, EvenLen);
            if(SubLen > MaxSubLen){
                substring = s.substr(i - (SubLen - 1) / 2 , SubLen ); 
                MaxSubLen = SubLen;
            }
        }
        return substring;
    }
};