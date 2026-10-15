class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        long long jumps =0;
        int l =0,r=0; // fo defining the range
        while(r<n-1)// if r crosses n , we have reavhed the end
        {
            int farthest =0;
            for(int idx =l;idx <= r;idx++)
            {
                farthest = max(farthest ,idx+nums[idx]);
            }
            l = r+1;
            r = farthest;
            jumps += 1;
        }
        return jumps;
    }
    // TC 0(n) as we are checking 1 no one by one in range and not 0(n^2)
};