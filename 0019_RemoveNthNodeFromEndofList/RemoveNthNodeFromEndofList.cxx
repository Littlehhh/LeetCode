/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * tmp = head;
        ListNode * prevNtmp = nullptr;
        int len = 1;
        while(tmp->next){
            tmp = tmp->next;
            ++len;
            if(len == n+1) prevNtmp = head;
            else if(len > n+1) prevNtmp = prevNtmp->next;
            else ;
        }
        if(len == 1 && n == 1) return nullptr;
        if(prevNtmp == nullptr) head = head->next;
        else{
            prevNtmp->next = prevNtmp->next->next;
        }

        return head;
    }
};