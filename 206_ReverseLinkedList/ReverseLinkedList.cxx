// Definition for singly-linked list.
#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head  == nullptr || head -> next == nullptr) return head;
        ListNode *tmp, *cur = nullptr;
        while(head->next){
           tmp = head->next;
           head->next = cur;
           cur = head;
           head = tmp;
        }
        head->next = cur;
        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* list = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return list;
    }
};
