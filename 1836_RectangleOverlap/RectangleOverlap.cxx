#include<vector>
using std::vector;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1.size() != 4 && rec2.size() != 4) return false;
        vector<int> p1_x {rec1[0], rec1[2]};
        vector<int> p2_x {rec2[0], rec2[2]};
        vector<int> p1_y {rec1[1], rec1[3]};
        vector<int> p2_y {rec2[1], rec2[3]};

        if( isLineOverlap(p1_x, p2_x) && isLineOverlap(p1_y, p2_y) )
            return true;
        else return false;
    }
    bool isLineOverlap(vector<int>& p1, vector<int>& p2){
        if(p1.size() != 2 && p2.size() != 2) return false;
        if( p2[0] < p1[0]  ){
            if( p2[1] > p1[0]) return true;
        }
        else {
            if( p2[0] < p1[1] ) return true;
        }
        return false;
    }
};

class Solution1 {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec2[0] >= rec1[2] || rec2[1] >= rec1[3] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3]);
    }
};

