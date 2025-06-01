class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans =0;
        for(int x = max(0,n-2*limit);x<= min(n,limit);x++)
        {
            int y_st = max(0,n-limit-x);
            int y_end = min(n-x,limit);
            if(y_st <= y_end)
            {
                long long range = (y_end - y_st +1);
                ans += range;
            }

        }
        return ans;
    }
};