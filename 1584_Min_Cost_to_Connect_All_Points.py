class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        adjList = {i:[] for i in range(n)}
        
        # getting edges:
        for i in range(n):
            x1, y1, = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dist = abs(x1-x2) + abs(y1-y2)
                adjList[i].append([dist, j])
                adjList[j].append([dist, i])

        # prims:
        result = 0
        visited = set()
        heap = [[0,0]] # min heap based on cost

        while len(visited) < n:
            cost, i = heapq.heappop(heap)

            if i not in visited:
                result += cost
                visited.add(i)

                for nbrCost, nbr in adjList[i]:
                    if nbr not in visited:
                        heapq.heappush(heap, [nbrCost, nbr])

        return result
