class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        for(int i =1;i<m;i++)
        {
            for(int j =0;j<n-1;j++)
            {
                if(mat[i-1][j] != mat[i][j+1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};