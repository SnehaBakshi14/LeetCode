class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i =0;// non-zero 
        for(int j =0;j<nums.size();j++)
        {
            if(nums[j] != 0)
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }
        // moves non-zero elements to right
    }
};