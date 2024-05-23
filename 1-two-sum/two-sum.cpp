class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<int> result(2);
        unordered_map<int,int> map;
        for(int i = 0;i<n;i++){
            map[nums[i]] = i;
        }

        for(int i =0;i<n;i++){
            if(map.find((target - nums[i])) != map.end() && i != map[(target-nums[i])]){
                return {i,map[(target-nums[i])]};
            }
        }
        return {};
        
    }
};