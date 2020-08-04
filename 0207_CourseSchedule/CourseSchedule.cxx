#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inD(numCourses, 0);
        vector< vector<int> > adjList( numCourses, vector<int>() );
        for(auto && p : prerequisites){
            adjList[p[1]].push_back(p[0]);
            inD[p[0]]++;
        }
        int sum = 0;
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(!inD[i]) q.push(i);
        }

        while(!q.empty()){
            auto c = q.front();
            q.pop();
            sum++;
            for(auto & it: adjList[c]){ 
                inD[it]--;
                if(!inD[it]) q.push(it);
            }
        }
        return sum == numCourses;

    }
};

