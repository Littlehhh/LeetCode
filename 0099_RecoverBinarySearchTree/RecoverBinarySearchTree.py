# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        s = list()
        prev = None
        x = None
        y = None
        while s or root:
            while root:
                s.append(root)
                root = root.left
            
            root = s.pop(-1)
            if prev and root.val < prev.val: 
                y = root
                if not x:
                    x = prev
                else: 
                    break
            prev = root
            root = root.right
        
        x.val, y.val = y.val, x.val
