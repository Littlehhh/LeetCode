#include<string>
#include<climits>
using std::string;


class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        bool IsNeg = false;
        bool IsBegin = true;
        for(auto&& ch = str.begin(); ch != str.end(); ++ch){
            if(*ch == '-' && IsBegin 
            && (ch+1)!=str.end() && (*(ch+1) > 47 && *(ch+1) < 58 ) ) 
                IsNeg = true;
            else if(*ch == '+' && IsBegin
            && ch+1!=str.end() && *(ch+1) > 47 && *(ch+1) < 58);
            else if(*ch == ' ' && IsBegin && !IsNeg) ;
            else if(*ch > 47 && *ch < 58){
                if(ans > INT_MAX / 10 && !IsNeg ) return INT_MAX;
                if(ans > INT_MAX / 10 && IsNeg ) return INT_MIN;
                ans = ans * 10 + *ch - 48;
                IsBegin = false;
            }
            else break;   
        }
        if(IsBegin) return 0;
        ans = IsNeg? -ans : ans;
        if( ans > INT_MAX ) return INT_MAX;
        else if( ans < INT_MIN ) return INT_MIN;
        else return ans;
    }
};