class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int MaxArea = 0;
        int Area = 0;

        while(left < right)
        {
            Area = (right-left)* min(height[left],height[right]);
            MaxArea = max(MaxArea,Area);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return MaxArea;
    }
};