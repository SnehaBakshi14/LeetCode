class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int c =0;
        int prefixsum =0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(int num : nums)
        {
            prefixsum = prefixsum+num;
            int rem = prefixsum%k;
            if(rem < 0)
            {
                rem+= k;
            }

            if(mp.find(rem) != mp.end())
            {
                c+= mp[rem];
                mp[rem] += 1;
            }
            else
            {
                mp[rem] =1;
            }
        }
        return c;
        
    }
};