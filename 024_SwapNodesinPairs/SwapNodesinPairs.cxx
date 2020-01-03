/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Recursion version
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * cur = head;
        ListNode * tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = cur;
        head = tmp;
        cur->next = swapPairs(cur->next);
        return head;
    }
};


// Recursion version
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// optim
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * newHead = head->next;
        head->next = newHead->next;
        newHead->next = head;
        head->next = swapPairs(head->next);
        return newHead;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * cur = head;
        head = head->next;
        ListNode * pre = new ListNode(-1);
        while(cur && cur->next){
            ListNode * tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            pre->next = tmp;
            pre = cur;
            cur = cur->next;
        }        
        return head;
    }
};
