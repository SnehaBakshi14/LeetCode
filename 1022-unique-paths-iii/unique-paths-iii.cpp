class Solution {
public:
    int totalWalkable = 0;
   

    int dfs(int r, int c, int visitedCount, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Boundary & obstacle / visited check
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1) {
            return 0;
        }

        // 2. Reached ending cell
        if (grid[r][c] == 2) {
            // Valid only if we visited every single walkable cell
            return (visitedCount == totalWalkable) ? 1 : 0;
        }

        // 3. Mark current cell as visited
        int temp = grid[r][c];
        grid[r][c] = -1; // Use -1 in-place to denote visited

        // 4. Explore all 4 directions
        int paths = dfs(r + 1, c, visitedCount + 1, grid)
                  + dfs(r - 1, c, visitedCount + 1, grid)
                  + dfs(r, c + 1, visitedCount + 1, grid)
                  + dfs(r, c - 1, visitedCount + 1, grid);

        // 5. Backtrack
        grid[r][c] = temp;

        return paths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startR = 0, startC = 0;
        totalWalkable = 0;

        // Count non-obstacle squares and identify start square position ie cell with value 1
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != -1) {
                    totalWalkable++;
                }
                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                }
            }
        }

        // Start DFS from start cell with count = 1
        return dfs(startR, startC, 1, grid);
    }
};