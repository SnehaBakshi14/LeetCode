class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        unordered_map<int,int> map;
        for(int i = 0;i<n;i++)
        {
            map[nums[i]] = i;//index ki mapping o_o
        }

        for(int i =0;i<n;i++){
            if(map[(target - nums[i])]  && i != map[(target-nums[i])])
            {
                return {i,map[(target-nums[i])]};
            }
        }
        return {-1,-1};
        
    }
};