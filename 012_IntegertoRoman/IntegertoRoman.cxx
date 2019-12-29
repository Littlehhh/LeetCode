#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans, num_s = to_string(num);
        vector< vector<string> > lookup = {{"IX", "V", "IV", "I"},
                                           {"XC", "L", "XL", "X"},
                                           {"CM", "D", "CD", "C"},
                                           {"*", "*", "*", "M"}};
        vector< int > number {9,5,4,1};
        int len = num_s.size();
        for(auto&& n : num_s){
            auto now = &lookup[len-1];
            int N = n-'0';
            auto cur = number.begin();
            while(N != 0){
                if(N < *cur)
                    ++cur;
                else{
                    N -= *cur;
                    ans+=(*now)[cur-number.begin()];
                }    
            }
            --len;
        }    
        return ans;
    }
};