class Solution {
public:
    int M = 1e9+7;
    int t[100001][2][3];

    int solve(int n,int abs,int conslate)
    {
        if(abs >= 2 ||conslate >= 3)
        {
            return 0;
        }

        if(n == 0)
        {
            return 1;
        }
        if(t[n][abs][conslate] != -1)
        {
            return t[n][abs][conslate];
        }

        int a = solve(n-1,abs+1,0) % M;//absent
        int l = solve(n-1,abs,conslate+1) % M;//late
        int p = solve(n-1,abs,0) % M;//present

        return t[n][abs][conslate] = ((a+l) % M + p ) % M;
    }

    int checkRecord(int n) 
    {
        memset(t,-1,sizeof(t));
        return solve(n, 0, 0);
    }
};