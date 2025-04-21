class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshcount = 0;
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1){
                    freshcount++;
                }
            }
        }

        int fresh = 0;
        int dr[] = {-1,0,0,1};
        int dc[] = {0,-1,1,0};

        int maxtime = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            maxtime = max(maxtime,t);
            q.pop();

            for(int k=0;k<4;k++){
                int i = r + dr[k];
                int j = c + dc[k];

                if(i < 0 || j < 0 || i>=m || j>=n || grid[i][j] != 1) continue;

                grid[i][j] = 2;
                q.push({{i,j},t+1});
                fresh++;
            }
        }
        if(fresh != freshcount) return -1;
        return maxtime;
    }
};