class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int XOR = 0;
        for(int i =0;i<nums.size();i++)
        {
            XOR ^= nums[i];
        }
        return XOR;
    }
};