class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto it : nums)
        {
            mp[it]++;
        }
        auto lambda = [&](int &num1,int &num2)
        {
            if(mp[num1] == mp[num2])
            {
                return num1>num2;// descending order
            }
            return mp[num1] < mp[num2];
        };
        sort(begin(nums),end(nums),lambda);
        return nums;
    }
};