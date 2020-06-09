#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        auto str = to_string(num);
        int pre = 1;
        int cur = 1;
        for(int i=2; i<=str.size(); ++i){
            int tmp = stoi(string(str.begin()+i-2, str.begin()+i));
            if( tmp >= 10 && tmp <= 25 ){
                tmp = cur;
                cur += pre;
                pre = tmp;
            }
            else{
                pre=cur;
            }
        }
        return cur;
    }
};