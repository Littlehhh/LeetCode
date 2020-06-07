#include<vector>
#include<string>
using namespace std;

class Solution1 {
public:
    // maximum 26 characters
    vector<int> parents = vector(26,0);
    // union find
    int find(int x) {
        if (x!=parents[x]) parents[x]=find(parents[x]);
        return parents[x];
    }
    void unionSet(int x, int y) {
        int xx = find(x);
        int yy = find(y);
        if (xx==yy) return;
        parents[xx] = yy;
    }
    bool connected(int x, int y) {
        if (find(x)==find(y)) return true;
        else return false;
    }
    // helper func
    int toInt(char c) {
        return c-'a';
    }
    // main
    bool equationsPossible(vector<string>& equations) {
        for (int i=0; i<26 ;i++) parents[i]=i;
        for (auto e : equations) if(e[1]=='=') unionSet(toInt(e[0]), toInt(e[3]));
        for (auto e : equations) if(e[1]=='!' && connected(toInt(e[0]), toInt(e[3]))) return false;
        return true;
    }
};

class Solution2 {
    class UnionFind{

        public: 
            vector<int> parents;
            int find(int x){
                int temp = x;
                while(x!= parents[x]) x= parents[x];
                while(temp != x){
                    int d = parents[temp];
                    parents[temp] = x;
                    temp = d;
                }
                return x;
            }
            void merge(int x, int y){
                int p1  = find(x), p2 = find(y);
                parents[p1] = p2;
            }
            bool is_connect(int x, int y){
                return find(x) == find(y);
            }
    };
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        uf.parents.resize(26);
        for(int i = 0;i< 26;i++){
            uf.parents[i] = i;
        }
        for(auto& eq: equations){
            char c = eq[1];
            if(c == '='){
             uf.merge(eq[0]- 'a', eq[3] - 'a');
            }
        }
        for(auto & eq : equations){
            char c = eq[1];
            
                if( c== '!' && uf.is_connect(eq[0] - 'a', eq[3] - 'a')) return false;
        }
        return true;
    }
};


class Solution {
public:
    int father[26];
    bool equationsPossible(vector<string>& equations) {
        //并查集
        //等于，则都应属于同一个集合，把等于两边的都放一个集合
        //然后看不等于两边的元素，是不是出现在同一个集合，如果有在一个集合的就是false
        if(equations.empty()) return true;
        //if(equations.size()==1) return true;
        //父亲先指向自己
        for(int i=0;i<26;i++){
            father[i] = i;
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){//等于，合并集合
                int fa1  = find(equations[i][0]-'a');
                int fa2  = find(equations[i][3]-'a');
                if(fa1!=fa2) father[fa1] = fa2;
            }
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                int fa1  = find(equations[i][0]-'a');
                int fa2  = find(equations[i][3]-'a');
                if(fa1==fa2) return false;
            }
        }
        return true;
    }

    //找跟节点
    int find(int i){
        //int fa = i;
        while(i!=father[i]){
            father[i] = father[father[i]];//顺便就路径压缩了
            i = father[i];
        }
        return i;
    }
};
