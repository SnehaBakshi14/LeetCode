class Solution {
public:
    //int fib(int n) 
    //{
        // Approach 1 Recursive,wastage
        // if(n == 0)
        // {
        //     return 0;
        // }
        // if(n==1 || n==2)
        // {
        //     return 1;
        // } 
        // return fib(n-1)+fib(n-2);    

        // Approach 2
        // vector<int> no(31,0);
        // no[0] = 0;
        // no[1] = 1;
        // for(int i = 2;i<=n;i++)
        // {
        //     no[i] = no[i-1]+no[i-2];
        // }
        // return no[n];
       // }

        // Approach 3 Recursion+Memoziation
        int solve(int n , vector<int>&dp)
        {
            if(n<=1)
            return n;

            if(dp[n]!=-1)
            return dp[n];

            return dp[n] = solve(n-1,dp)+solve(n-2,dp);

        }
        int fib(int n)
        {
            if(n <= 1)
            return n;

            vector<int>dp(n+1,-1);
            
            return solve(n,dp);
        }
};