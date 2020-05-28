#include<vector>
#include<queue>
using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        auto lo = lists.begin();
        auto hi = --lists.end();
        ListNode * merge = nullptr;
        while(lo < hi){
            ListNode * tmp = mergeTwoLists(*lo, *hi);
            ++lo;--hi;
            merge = mergeTwoLists(merge, tmp);
        }
        merge = *lo == *hi ? mergeTwoLists(*lo, merge) : merge;
        return merge;
    }

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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* merge = spiltLists(lists, 0, lists.size()-1);
        // auto lo = lists.begin();
        // auto hi = --lists.end();
        // ListNode * merge = nullptr;
        // while(lo < hi){
        //     ListNode * tmp = mergeTwoLists(*lo, *hi);
        //     ++lo;--hi;
        //     merge = mergeTwoLists(merge, tmp);
        // }
        // merge = *lo == *hi ? mergeTwoLists(*lo, merge) : merge;
        return merge;
    }

    ListNode* spiltLists(vector<ListNode*>& lists,int left,int right){
        if(left == right) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode * l1 = spiltLists(lists, left, mid);
        ListNode * l2 = spiltLists(lists, mid+1, right);
        return mergeTwoLists(l1, l2);

    }
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

class Solution {
public:
    using Compare = function<bool(const ListNode*, const ListNode*)> ;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        Compare cmp = [](const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, Compare> q(cmp);
        for (auto& p: lists) {
            if (p) q.push(p);
        }
        ListNode *dummy = new ListNode(-1);
        auto tail = dummy;
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            if (cur->next) q.push(cur->next);
            tail->next = cur;
            tail = cur;
        }
        return dummy->next;
    }
};
