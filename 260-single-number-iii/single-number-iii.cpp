class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int ch : nums)
        {
            mp[ch]++;
        }
        for(auto x : mp)
        {
            if(x.second == 1)
            ans.push_back(x.first);

        }
        return ans;
    }
};