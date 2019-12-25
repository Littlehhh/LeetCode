#include<string>
using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() && !p.size()) return false;
        
        auto && it_s = s.begin();
        auto && it_p = p.begin();
        char p_prev = *it_p;
        while(it_p != p.end()){
            // status *
            if( it_p+1 != p.end() && *(it_p+1) == '*' ){
                p_prev = *it_p;
                it_p = it_p + 2;
                while( it_s != s.end() && (p_prev == *it_s || p_prev == '.') ){
                        if( isMatch( string(it_s, s.end()) , string( it_p, p.end()) ) )
                            return true;
                        else ++it_s;
                }
            }
            // status . and ==
            else if( it_s != s.end() && (*it_p == '.' || *it_s == *it_p)){
                p_prev = *it_p;
                ++it_s; ++it_p; 
            }
            else return false;
        }
        if(it_s != s.end()) return false;
        return true;
    }
};