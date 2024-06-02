class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, -1)); // Initialize vis array with -1
        int cntFresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Rotten orange
                } else if(grid[i][j] == 1) {
                    cntFresh++; // Count fresh oranges
                }
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int tm = 0;
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t); // Update maximum time
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == -1 && grid[nr][nc] == 1) {
                    q.push({{nr, nc}, t + 1}); // Push fresh orange to rot
                    vis[nr][nc] = 2; // Mark as rotten
                    cntFresh--; // Decrease the count of fresh oranges
                }
            }
        }
        if(cntFresh > 0) return -1; // All oranges should be rotten
        return tm; // Return the minimum time
    }
};
