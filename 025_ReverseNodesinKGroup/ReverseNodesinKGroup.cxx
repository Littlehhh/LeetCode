struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * newHead = head;
        ListNode * cur = head;
        int n = k;
        while(--n && newHead){
            newHead = newHead->next;
        }
        if(n > 0 || newHead == nullptr) return head;
        n=k;
        while(--n){
            ListNode * tmp = cur;
            cur = cur->next;
            tmp->next = newHead->next;
            newHead->next = tmp;
        }
        head->next = reverseKGroup(head->next, k);
        return newHead;
    }
};