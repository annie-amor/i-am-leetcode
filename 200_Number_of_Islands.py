class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        islands = 0
        rows, cols = len(grid), len(grid[0])
        visited = set()

        def bfs(r,c):
            visited.add((r,c))
            q = deque()
            q.append((r,c))
           
            while q:
                row, col = q.popleft()
                directions= [[0,-1],[0,1],[1,0],[-1,-0]]
               
                for dRow, dCol in directions:
                    r, c = row + dRow, col + dCol
                    if (r in range(rows) and
                        c in range(cols) and
                        grid[r][c] == '1' and
                        (r, c) not in visited
                    ):
                        q.append((r, c))
                        visited.add((r, c))

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)
                    islands +=1 

        return islands
