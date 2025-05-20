class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int start = 0;
        int end = m*n -1;
        while(start <= end)
        {
            int mid = start + (end- start)/2;
            if(mat[mid/n][mid%n] > target)
            {
                // target in left
                end = mid-1;
            }
            else if(mat[mid/n][mid%n] < target)
            {
                start = mid+1;
                // target in right
            }
            else
            {
                return true;
            }
            
        }
        return false;
    }
};