class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid,int &cnt){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != 1) return ;

        grid[i][j] = 2;
        cnt++;
        dfs(i-1,j,m,n,grid,cnt);
        dfs(i,j-1,m,n,grid,cnt);
        dfs(i,j+1,m,n,grid,cnt);
        dfs(i+1,j,m,n,grid,cnt);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        int maxi = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    cnt = 0;
                    dfs(i,j,m,n,grid,cnt);
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};