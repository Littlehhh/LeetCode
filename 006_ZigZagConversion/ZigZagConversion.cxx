#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        size_t len = s.size();
        std::string ans = string();
        
        for(int i=0; i<numRows; i++){
            int increment = 2*(numRows-1);
            int flag = true;
            for(int j=i; j < len; j=j+increment){
                if( i % (numRows -1 ) != 0)
                    if( flag )
                        increment = 2*(numRows-1) - i - i;
                    else
                        increment = i + i;  
                    flag = !flag;
                ans.push_back(s[j]);
            }
        }
        return ans;
    }
};