#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * newHead = head;
        ListNode * cur = head;
        int n = k;
        // find new head
        while(--n && newHead){
            newHead = newHead->next;
        }
        if(n > 0 || newHead == nullptr) return head;
        n=k;
        // reverse one group
        while(--n){
            ListNode * tmp = cur;
            cur = cur->next;
            tmp->next = newHead->next;
            newHead->next = tmp;
        }
        // now the head is tail and than reverse remain groups
        head->next = reverseKGroup(head->next, k);
        return newHead;
    }
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> s;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* tmp = head, *p = dummy;
        while (true){
            int count = 0;
            ListNode* tmphead = tmp;
            while (tmp && count < k ){
                s.push(tmp);
                tmp = tmp->next;
                ++count;
            }
            if (count < k) {
                p->next = tmphead;
                break;
            }
            while (!s.empty()){
                p->next = s.top();
                s.pop();
                p = p->next;
                p->next = nullptr;
            }
        }
        return dummy->next;
    }
};