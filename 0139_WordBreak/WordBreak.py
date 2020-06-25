from collections import Counter

class Solution1:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp=[False]*(len(s)+1)
        dp[0]=True
        Dict = Counter(wordDict)
        for i in range(len(s)):
            for j in range(0,i+1):
                if s[j:i+1] in Dict and dp[j]:
                    dp[i+1]=True
                    break

        return dp[-1]

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not wordDict:
            return False
        n = len(s)
        
        result = [False] * (n + 1)
        result[0] = True
        
        for i in range(n):
            if not result[i]:
                continue
            for w in wordDict:
                end = i + len(w)
                if end <= n and not result[end] and s[i: end] == w:
                    result[end] = True
        return result[-1]