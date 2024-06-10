class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int>c(begin(heights),end(heights));
        sort(begin(heights),end(heights));
        int count =0;
        for(int i =0;i<heights.size();i++)
        {
            if(c[i] != heights[i])
            {
                count++;
            }
        }
        return count;
    }
};