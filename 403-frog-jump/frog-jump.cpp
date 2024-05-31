class Solution {
public:
int n;
unordered_map<int,int>mp;// stores index of stones
int t[2001][2001];
    int  solve(vector<int>& stones,int csi,int pj)
    {
        bool result = false;
        if(csi == n-1)
        return true;

        if(t[csi][pj] != -1)
        {
            return t[csi][pj];
        }

        for(int nextjump = pj-1;nextjump<=pj+1 ;nextjump++)// will check for all three possibilities
        {
            if(nextjump>0)// -1 and zero(same position) pr check krne ki zarurat nahi h
            {
                int nextstone = stones[csi]+nextjump;
                if(mp.find(nextstone)!=mp.end())
                {
                    result = result||solve(stones,mp[nextstone],nextjump);
                } 
            }
        }
        return t[csi][pj] = result;
    }
    bool canCross(vector<int>& stones)
    {
        n = stones.size();
        if(stones[1] != 1)
        return false;// start hamesha 0 se hain toh 1 unit jump kr ke 1 pe ana chaiye

        for(int i =0;i<n;i++)
        {
            mp[stones[i]]=i;// store index with stone
        }
        memset(t,-1,sizeof(t));

        return solve(stones, 0 , 0);// current stone index = 0, previous jump =0;
    }
};
