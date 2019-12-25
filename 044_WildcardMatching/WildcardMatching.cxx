# include<string>
using std::string;
// beyond time limit
class Solution {
public:
    bool isMatch(string s, string p) {        
        auto && it_s = s.begin();
        auto && it_p = p.begin();
        while(it_p != p.end()){
            // status *
            if( *(it_p) == '*' ){
                ++it_p;
                while( it_s != s.end() ){
                        if( isMatch( string(it_s, s.end()) , string( it_p, p.end()) ) )
                            return true;
                        else ++it_s;
                }
            }
            // status ? and ==
            else if( it_s != s.end() && (*it_p == '?' || *it_s == *it_p)){
                ++it_s; ++it_p; 
            }
            else return false;
        }
        if(it_s != s.end()) return false;
        return true;
    }
};