class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != '1') return ;

        grid[i][j] = 'S';

        dfs(i-1,j,m,n,grid);
        dfs(i,j-1,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i+1,j,m,n,grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,m,n,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};