class Solution {
public:
    int t[301][5001];// change is in index and amount
    int n;
    int solve(int i,int amt,vector<int>& coins)
    {
        if(amt == 0)
        return 1;//1 way found

        if(i==n)
        return 0;//index out of bound

        if(t[i][amt] != -1)
        {
            return t[i][amt] ;
        }

        if(amt < coins[i])
        {
            return t[i][amt] = solve(i+1,amt,coins);// has to skip
        }

        int take = solve(i,amt-coins[i],coins);
        int skip = solve(i+1,amt,coins);

        return t[i][amt] = take+skip;// total no of ways
    }

    int change(int amt, vector<int>& coins) 
    {
        n = coins.size();
        memset(t,-1,sizeof(t));
        return solve(0,amt,coins);
        
    }
};