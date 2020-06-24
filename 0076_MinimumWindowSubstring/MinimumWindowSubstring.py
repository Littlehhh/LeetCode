from collections import defaultdict, Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t): return ""
        need = Counter(t) 
        window = defaultdict(int)
        left=0
        right=0
        valid=0
        start=0
        lenW=float('inf')
        while right < len(s):
            ch = s[right]
            right+=1

            if ch in need:
                window[ch]+=1
                if window[ch] == need[ch]:
                    valid+=1
            
            while valid == len(need):
                if right-left < lenW:
                    lenW=right-left
                    start=left
                leftCh=s[left]
                left+=1
                if leftCh in need:
                    if window[leftCh] == need[leftCh]:
                        valid-=1
                    window[leftCh]-=1        
        return s[start: start+lenW] if lenW < float('inf') else ""