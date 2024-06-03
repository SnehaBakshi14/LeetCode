class Solution {
public:
int row,col;
    void DFS(int i,int j,vector<vector<int>>& grid,int& walls)
    {
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == 0)
        {
            walls++;// either reached out of boundary or water
            return;
        }
        if(grid[i][j] == -1)
        {
            return ;
        }
        grid[i][j] = -1;

        DFS(i+1,j,grid,walls);
        DFS(i-1,j,grid,walls);
        DFS(i,j+1,grid,walls);
        DFS(i,j-1,grid,walls);
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        
        row = grid.size();
        col = grid[0].size();
        int walls = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    DFS(i,j,grid,walls);
                    return walls;
                }
            }
        }
        return -1;
    }
};
