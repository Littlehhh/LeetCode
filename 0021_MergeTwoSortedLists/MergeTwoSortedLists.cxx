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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(-1);
        ListNode * tmp = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }
            else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = l1 ? l1 : l2;
        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = l1->val < l2->val ? l1 : l2;
        ListNode *nonHead = l1->val < l2->val ? l2 : l1;
        head->next = mergeTwoLists(head->next, nonHead);
        return head;
    }
};