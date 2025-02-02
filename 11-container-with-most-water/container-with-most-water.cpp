class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int area = 0;
        int maxarea = 0;
        int i =0, j= n-1;
        while(i < j)
        {
            int width = j-i;
            int h = min(height[i],height[j]); 
            // pani kahan tk store hoga jo bhi minimum height hogi vha tk
            area = width*h;
            maxarea = max(area,maxarea);
            if(height[i] >= height[j]) 
            // as you are decreasing the width try to keep the longer height , `            greedily apne pass badi height rakho 
            {
                j--;
            }
            else
            {
                i++;
            }
            
        }
        return maxarea;
    }
};