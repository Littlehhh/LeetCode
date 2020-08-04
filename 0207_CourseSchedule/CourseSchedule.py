import queue
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inD = [0]*numCourses
        adjList = [list() for _ in range(numCourses)]
        for cur, pre in prerequisites:
            adjList[pre].append(cur)
            inD[cur]+=1
        S = 0
        q = queue.Queue()
        for i in range(numCourses):
            if inD[i] == 0:
                q.put(i)

        while not q.empty():
            tmp = q.get()
            S+=1
            for c in adjList[tmp]:
                inD[c]-=1
                if not inD[c]: 
                    q.put(c)
        return S == numCourses
