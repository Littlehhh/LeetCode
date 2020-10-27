#include<vector>
#include<queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return {};
        Node * ans = new Node(node->val);
        vector<Node*> vis(101, nullptr);
        queue<Node*> q;
        q.push(node);
        vis[node->val] = ans;
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            for(auto && neighbor:tmp->neighbors){
                int id = neighbor->val;
                if(!vis[id]){
                    vis[id] = new Node(id);
                    q.push(neighbor);
                }
                vis[tmp->val]->neighbors.emplace_back(vis[id]);
            }
        }
        return ans;
    }
};