class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(auto i : nums)
        {
            mp[i]++;
        }
        for(auto i : mp)
        {
            pq.push({i.second,i.first});
        }
        vector<int> ans;
        while(k-- && !pq.empty())
        {
            int p = pq.top().second;
            ans.push_back(p);
            pq.pop();
        }
        return ans;

    }
};