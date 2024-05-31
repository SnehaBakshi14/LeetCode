class Solution {
public:
    long long t[1000001][2];
    int n;
    typedef long long ll;
    ll solve(int idx, vector<int>&nums,bool flag)
    {
        if(idx>=n)
        return 0;

        if(t[idx][flag] != -1)
        {
            return t[idx][flag];
        }
        ll skip = solve(idx+1,nums,flag);
        ll val = nums[idx];
        if(!flag)// flag is false odd index 
        {
            val = -val;
        }
        ll take = val + solve(idx+1,nums,!flag);

        return t[idx][flag] = max(take,skip);

    }
    long long maxAlternatingSum(vector<int>& nums) 
    {
        n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,true);// 0th index as idx and true = + (even index)
        
    }
};