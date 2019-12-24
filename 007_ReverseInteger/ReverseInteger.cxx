#include<string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if (s[0] == '-') std::reverse(s.begin()+1, s.end());
        else std::reverse(s.begin(), s.end());
        try
        {   return std::stoi(s); }    
        catch(const std::exception& e){
            return 0;
        }     
    }
};