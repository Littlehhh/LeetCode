#include<map>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> lookup = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> parse;
        for(auto& sym:s){
            auto found = lookup.find(sym);
            if(found == lookup.end()){
                parse.push(sym);
            }
            else{
                if( !parse.empty() && found->second == parse.top() ) parse.pop();
                else return false;
            }
        }
        return parse.empty();
    }
};