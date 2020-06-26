
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode * ob = head;
        while(ob){
            ListNode * oc = ob;
            while(oc->next){
                if(oc->next->val == ob->val){
                    oc->next = oc->next->next;
                }
                else oc = oc->next;
            }
            ob = ob->next;
        }
        return head;
    }
};