// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* pos = ans;
        int carray_flag = 0;
        while( l1 || l2 ){
            int sum = 
            (l1?l1->val:0)+(l2?l2->val:0)+carray_flag;
            carray_flag = sum / 10 ? 1:0;
            // steal the space
            pos->next = l1 ? l1:l2;
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
            pos->next->val = sum % 10;
            pos = pos->next;
        }
        // process boundary
        if(carray_flag){
            pos->next = ans;
            ans->val = carray_flag;
            ans = ans->next;
            pos->next->next = nullptr;
        } 
        else
            ans = ans->next;
        return ans;
    }
};