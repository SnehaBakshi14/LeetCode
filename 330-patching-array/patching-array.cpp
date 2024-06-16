class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        long long maxreached = 0;
        int patch =0;
        int i=0;
        while(maxreached < n)
        {
            if(i < nums.size() && nums[i] <= maxreached+1)
            {
                maxreached += nums[i];
                i++;
            }
            else
            {
                //patch krna padega
                
                maxreached += (maxreached+1);
                patch++;
            }
        }
        return patch;
        
    }
};