class Tries:
    def __init__(self):
        self.next_ch = '-'
        self.next_node = None
    
    
    def init(self, string:str):
        node = self
        for ch in string:
            node.next_ch=ch;
            node.next_node=Tries()
            node = node.next_node
    
    def CommonPrefix(self, string:str):
        node = self
        for ch in string:
            if node.next_ch == '-':
                break
            if node.next_ch != ch:
                node.next_ch='-'
                node.next_node = None
                break
            node = node.next_node
        node.next_ch='-'
        node.next_node=None
        

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''
        if len(strs) == 1: 
            return strs[0]
        root = Tries()
        root.init(strs[0])
        for string in strs[1:]:
            root.CommonPrefix(string)
        ans = ''
        while root.next_ch!='-':
            ans+=root.next_ch
            root=root.next_node
        return ans