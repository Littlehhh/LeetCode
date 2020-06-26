# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head: return head
        Dict = [0]*20001
        cur = head
        Dict[head.val]=1
        while cur.next:
            if Dict[cur.next.val]==0:
                Dict[cur.next.val]=1
                cur=cur.next
            else:
                cur.next=cur.next.next
        return head