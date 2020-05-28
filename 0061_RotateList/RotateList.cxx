#include<cstddef> // for NULL

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        ListNode * tail = head;
        int cnt = 1;
        while(tail->next){
            tail = tail->next;
            cnt++;
        } 
        tail->next = head;
        int mv = cnt - k%cnt - 1;
        while(mv--){
            head = head->next;
        }
        ListNode *tmp = head;
        head = head->next;
        tmp->next = nullptr;
        return head;
    }
};