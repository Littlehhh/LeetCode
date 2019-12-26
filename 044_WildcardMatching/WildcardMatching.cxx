#include<string>
#include<vector>
#include<iostream>
using std::vector;
using std::string;
using std::distance;
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


static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution2 {
public:
    bool isMatch(string s, string p) {                
        vector< vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        // str "" condition
        for( int j = 1; j < dp[0].size(); ++j){
            if( p[j-1] == '*') dp[0][j] = true;
            else break;
        }
        // for( int i = 1; i < dp.size() ; ++i){
        //     for( int j = 1; j < dp[0].size(); ++j){
        //         if( p[j-1] == '*'){
        //             dp[i][j] = dp[i][j-1] || dp[i-1][j];
        //         }
        //         else if(p[j-1]=='?' || s[i-1]==p[j-1]){
        //             dp[i][j] = dp[i-1][j-1];
        //         }
        //         else ;
        //     }
        // }
        

        for(auto && str : s){
            int s_index = 0;
            // int s_index = distance(&str, &s[0]);
            for(auto && pattern : p){
                int p_index = 0;
                // int p_index = distance(&pattern, &p[0]);
                // cout << str << " " << pattern << endl;
                if(pattern == '*'){
                    dp[s_index+1][p_index+1] = dp[s_index+1][p_index] || dp[s_index][p_index+1];
                }
                else if( pattern == str || pattern == '?'){
                    dp[s_index+1][p_index+1] = dp[s_index][p_index];
                }
                else ;
                ++p_index;
            }
            ++s_index;
        }
        return  dp[s.size()][p.size()];


    }
};

int main(int argc, char * argv[]){
    string a = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    string b = "a*******b";
    Solution2 s = Solution2();
    std::cout <<  s.isMatch(a,b);

    return 0;
}