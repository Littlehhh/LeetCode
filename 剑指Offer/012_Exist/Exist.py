class Solution1:
    def exist(self, board: List[List[str]], word: str) -> bool:
        dx=[1,0,-1,0]
        dy=[0,1,0,-1]
        def dfs(row, col, w_idx)->bool:
            if not 0<=row<len(board) or not 0<=col<len(board[0]) or board[row][col] != word[w_idx]: return False
            if w_idx == len(word)-1: return True
            tmp = board[row][col]
            board[row][col] = '/'
            for i in range(4):
                if dfs(row+dx[i], col+dy[i], w_idx+1):
                    return True
            board[row][col] = tmp
            return False
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if collections.Counter(word) - collections.Counter(itertools.chain(*board)):
            return False
        m, n, l = len(board), len(board[0]), len(word)
        d = ((0, 1), (1, 0), (0, -1), (-1, 0))
        def f(i, j, t):
            if t == l - 1:
                return board[i][j] == word[-1]
            v, board[i][j] = board[i][j], ''
            return any(
                0 <= (x := i + r) < m and \
                0 <= (y := j + c) < n and \
                board[x][y] == word[t + 1] and \
                f(x, y, t + 1)
                for r, c in d
            ) or board[i].__setitem__(j, v)
        return any(
            f(i, j, 0) 
            for i, j in itertools.product(range(m), range(n)) 
            if board[i][j] == word[0]
        )
    
    