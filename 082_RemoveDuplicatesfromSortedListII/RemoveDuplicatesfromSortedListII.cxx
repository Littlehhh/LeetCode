
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == nullptr || head->next == nullptr) return head;
        ListNode * tmpHead = new ListNode(-1);
        tmpHead->next = head;
        ListNode * lo = tmpHead;
        while(lo->next){
            ListNode * tmp = lo->next;
            if( tmp->next && tmp->val == tmp->next->val){
                while(tmp->next && tmp->val == tmp->next->val){
                    tmp = tmp->next;
                }
                lo->next = tmp->next;
                
            }
            else lo = lo->next;
        }
        return tmpHead->next;
    }
};