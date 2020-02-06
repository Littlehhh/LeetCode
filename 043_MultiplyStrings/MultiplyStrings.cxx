#include<string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int len = num1.size()+num2.size();
        int * res{ new int[len]{}};
        for( int i = num1.size()-1; i>=0; --i){
            int n1 = num1[i] - '0';
            for(int j = num2.size()-1; j>=0; --j){
                int n2 = num2[j] - '0';
                int sum = res[i+j+1]+n1*n2;
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        string ans;
        for(int i=0; i<len; ++i){
            if(i==0 && res[i] == 0) continue;
            ans.push_back(res[i]+'0');
        }
        return ans;
    }
};