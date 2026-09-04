class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int>minfromindex(n);
        int mini = INT_MAX;
        for(int i = n-1;i>=0;i--)
        {
            mini = min(mini,nums[i]);
            minfromindex[i] = mini;// preprocessing min(nums[i..n - 1]) for each index 
        }
        int maxi = INT_MIN;
        for(int i =0;i<n;i++)
        {
            maxi = max(maxi, nums[i]);
            mini = minfromindex[i];
            if(maxi - mini <= k)
            {
                return i;
            }
        }
        return -1;
    }
    // TC o(n)
};