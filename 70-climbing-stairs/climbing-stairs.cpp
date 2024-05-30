class Solution {
public:
    //Approach 1 Bruteforce TLE
    // int solve(int n) 
    // {
    //     if(n<0)
    //     return 0;

    //     if(n==0)
    //     return 1;

    //     int one_step = solve(n-1);
    //     int two_step = solve(n-2);

    //     return one_step+two_step;
    // }
    // int climbStairs(int n) 
    // {
    //     return solve(n);
    // }

    //Approach 2 Memoization
    // int t[46];
    // int solve(int n)
    // {
    //     if(n < 0)
    //     return 0;

    //     if(t[n] != -1)
    //     return t[n];

    //      if(n==0)// we found one way to climb stairs
    //     return 1;

    //     int one_step = solve(n-1);
    //     int two_step = solve(n-2);

    //     return t[n] = one_step+two_step;
    // }
    // int climbStairs(int n)
    // {
    //     memset(t,-1,sizeof(t));
    //     return solve(n);
    // }


    // Approach 3 Bottoms down
    int climbStairs(int n)
    {
        vector<int> t(n+1);
         if(n==1 || n==2)
        return n;

        t[0]=0;
        t[1]=1;
        t[2]=2;

        for(int i=3;i<=n;i++)
        {
            t[i] = t[i-1]+t[i-2];
        }
        return t[n];
    }

};