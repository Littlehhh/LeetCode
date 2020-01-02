/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        //  cur  ->  tmp
        ListNode * cur = head;
        ListNode * tmp = nullptr;
        
        tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = cur;
        head = tmp;
        
        while(cur->next){
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            cur = cur->next;
        }
        return head;
    }
};
