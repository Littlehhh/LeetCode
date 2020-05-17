from collections import deque 

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjList = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        ans = list()
        q = deque()
        for second,first in prerequisites:
            adjList[first].append(second)
            indegree[second] += 1

        for vertex in range(numCourses):
             if indegree[vertex] == 0:
                 q.append(vertex)
        while q:
            tmp = q[0]
            q.popleft()
            ans.append(tmp)

            for vertex in adjList[tmp]:
                indegree[vertex] -= 1
                if indegree[vertex] == 0:
                    q.append(vertex)
        
        if len(ans) != numCourses:
            return []
        else:
            return ans
