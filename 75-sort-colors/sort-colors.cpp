class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i =0;
        int j = nums.size()-1;
        int idx = 0;
        int n = nums.size();
        while(idx<=j)
        {
            if(nums[idx] == 0)
            {
                swap(nums[idx],nums[i]);
                {
                    i++;
                    idx++;
                }
            }
            else if(nums[idx] == 2)
            {
                swap(nums[idx],nums[j]);
                {
                    j--;
                }
            }
            else
            {
                idx++;
            }

        }
    }
};