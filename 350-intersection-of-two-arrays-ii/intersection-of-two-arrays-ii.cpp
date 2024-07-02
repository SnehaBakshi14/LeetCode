class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int>mp;
        for(int&num : nums1)
        {
            mp[num]++;
        }
        vector<int>result;
        for(int i =0;i<nums2.size();i++)
        {
            int n = nums2[i];
            if(mp[n] > 0)
            {
                mp[n]--;
                result.push_back(n);
            }
        }
        return result;
    }
};