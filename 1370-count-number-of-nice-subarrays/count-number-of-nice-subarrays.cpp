class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        unordered_map<int,int>mp;// to remember odd count if we have seen it in past or not
        int result = 0;
        int oddc = 0;
        mp[oddc]=1;//seen odd count = 0 in past
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            oddc += (nums[i]%2 == 0)?0:1;
            if(mp.count(oddc - k))
            {
                result += mp[oddc - k];
            }
            mp[oddc]++;

        }
        return result;
    }
};