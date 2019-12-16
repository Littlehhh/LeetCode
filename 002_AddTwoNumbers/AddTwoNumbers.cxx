


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
        bool carray_flag = false;
        while( l1 && l2 ){
            int sum = 0;
            if(carray_flag){
                sum = l1->val + l2->val + 1;
                carray_flag = false;
            }
            else 
                sum = l1->val + l2->val;
            if(  sum / 10 ) carray_flag = true;
            pos->next = new ListNode(sum % 10);
            pos = pos->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = 0;
            if(carray_flag) {
                sum = l1->val+1;
                carray_flag = false;
            }
            else
                sum = l1->val;
            if(  sum / 10 ) carray_flag = true;
            pos->next = new ListNode(sum % 10);
            pos = pos->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = 0;
            if(carray_flag) {
                sum = l2->val+1;
                carray_flag = false;
            }
            else
                sum = l2->val;
            if(  sum / 10 ) carray_flag = true;
            pos->next = new ListNode(sum % 10);
            pos = pos->next;
            l2 = l2->next;
        }
        // boundary
        if(carray_flag) 
            pos->next = new ListNode(1);

        return ans->next;
    }
};