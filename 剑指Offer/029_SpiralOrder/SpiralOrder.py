class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]: 
            return []
        u,d,l,r = 0,len(matrix)-1,0,len(matrix[0])-1
        ans = [0]*len(matrix)*len(matrix[0])
        idx=0
        while True:
            for i in range(l, r+1):
                ans[idx] = matrix[u][i]
                idx+=1
            u+=1
            if u > d:
                break
            for i in range(u,d+1):
                ans[idx] = matrix[i][r]
                idx+=1
            r-=1
            if l > r:
                break
            for i in range(r, l-1, -1):
                ans[idx] = matrix[d][i]
                idx+=1
            d-=1
            if u > d:
                break
            for i in range(d, u-1, -1):
                ans[idx] = matrix[i][l]
                idx+=1
            l+=1
            if l > r:
                break
        return ans

