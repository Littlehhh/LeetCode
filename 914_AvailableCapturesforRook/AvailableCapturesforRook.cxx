#include<vector>
#include<numeric>
using namespace std;

class Solution {
    int cnt[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for (auto x: deck) cnt[x]++;
        int g = -1;
        for (int i = 0; i < 10000; ++i)if(cnt[i]) {
            if (~g) g = gcd(g, cnt[i]);
            else g = cnt[i];
        }
        return g >= 2 ? true : false;
    }
};
