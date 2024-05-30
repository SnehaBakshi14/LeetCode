class Solution {
public:
    int t[101];
    int solve(vector<int>& nums,int i,int n)
    {
        if(i>n)// its not i >= n bcs here n is index not size 
        return 0;

        if(t[i] != -1)
        {
            return t[i];
        }

        int steal = nums[i]+solve(nums,i+2,n);
        int skip = solve(nums,i+1,n);

        return t[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        if(n == 1)// only 1 house
        return nums[0];
        
        if(n == 2)//house are in circle and adjacent
        return max(nums[0],nums[1]);

        memset(t,-1,sizeof(t));
        int take0th = solve(nums,0,n-2);//n-2 is index

        memset(t,-1,sizeof(t));
        int nottake0th = solve(nums,1,n-1);//n-1 is index

        return max(take0th, nottake0th);
    }
};