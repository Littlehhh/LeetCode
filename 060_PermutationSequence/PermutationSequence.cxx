#include<string>
#include <algorithm>
using std::string;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = string("123456789").substr(0,n);
        while(--k>0){
            std::next_permutation(s.begin(), s.end());
        }
        return s;
    }
    
};

// Possible implementation
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