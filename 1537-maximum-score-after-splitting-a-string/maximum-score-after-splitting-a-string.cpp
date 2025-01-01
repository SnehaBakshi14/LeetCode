class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.length();
        int zero = 0;
        int ones = 0;
        int res = INT_MIN;
        int total_ones = count(begin(s),end(s),'1'); // 1st pass 
        // right_ones = total_ones - ones
        for(int i = 0 ; i <= n-2; i++)
        {
            // n-2 because we dont want any empty substring 
            if(s[i] == '1')
            {
                ones++;
            }
            else
            {
                zero++;
            }
           int  right_ones = total_ones - ones;
           res = max(res , zero+right_ones);
        }
        return res;
    }
};