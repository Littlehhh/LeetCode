#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string ans;
        while(ss >> ans);
        return ans.size();
    }
};