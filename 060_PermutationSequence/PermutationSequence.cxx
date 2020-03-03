#include<string>
#include<algorithm>
#include<vector>
using std::string;
using std::vector;

class Solution1 {
public:
    string getPermutation(int n, int k) {
        string s = string("123456789").substr(0,n);
        while(--k>0){
            std::next_permutation(s.begin(), s.end());
        }
        return s;
    }
    
};

// Possible implementation cpp doc
template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

// cantor encode decode
class Solution {
    vector<int> fac;
public:
    string getPermutation(int n, int k) {
        string ans;
        string s = string("123456789").substr(0, n);
        generateFac(n);
        --k;
        while(k > 0)
        {  
            size_t i = k/fac[n - 1];
            ans.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac[n - 1];
            --n;
        }
        return ans + s;
    }
    void generateFac(int n){
        fac.emplace_back(1);
        fac.emplace_back(1);
        for(int i = 2; i < n; ++i){
            fac.emplace_back( i * fac[i-1] );
        }
        return;
    }
};
