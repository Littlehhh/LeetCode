#include<stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    // 先入后出的性质
    // 同时入栈值和当前最小值
    stack<pair<int, int>> s;
    MinStack() {
        
    }
    void push(int x) {
        if(s.empty()){
            s.emplace(make_pair(x,x));
        }
        else{
            s.emplace(make_pair(x, std::min(x, s.top().second)));
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */