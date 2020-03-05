#include<vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0){
            digits.emplace_back(1);
            return digits;
        }
        int carry = 1;
        for(int i = digits.size()-1; i >=0 ; --i){
            int sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if(carry !=0) digits.insert(digits.begin(), carry);
        return digits;
    }
};
