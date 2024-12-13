class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();
        vector<pair<int,int>>p(n);

        for(int i = 0;i<n;i++)
        {
            p[i] = {nums[i],i};
        }
        sort(p.begin(),p.end());

        long long score =0;
        for(int i =0;i<n;i++)
        {
            int no = p[i].first;
            int idx = p[i].second;

            if(nums[idx] !=  -1)
            {
                score += no;
                nums[idx] =-1;
                if(idx >0)
                {
                    nums[idx-1] = -1;
                }
                if(idx < n-1)
                {
                    nums[idx+1] = -1;
                }
            }
        }
        return score;
        
    }
};