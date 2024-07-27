class Solution {
public:
    void floydwarshall(vector<vector<long long>>&adjmat,vector<char>&orignal,vector<char>&changed,vector<int>&cost)
    {
        for(int i =0;i<orignal.size();i++)
        {
            int s = orignal[i] - 'a';// to find index
            int t = changed[i] - 'a';
            adjmat[s][t] = min(adjmat[s][t] , (long long)cost[i]);
        }
        // Apply floyd warshall
        for(int k =0;k<26;k++)
        {
            for(int i =0;i<26;i++)
            {
                for(int j =0 ; j<26;j++)
                {
                    adjmat[i][j] = min(adjmat[i][j] , adjmat[i][k] + adjmat[k][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        vector<vector<long long>>adjmat(26,vector<long long>(26,INT_MAX));
        floydwarshall(adjmat,original,changed,cost);
        long long ans =0;

        for(int i =0;i<source.length();i++)
        {
            if(source[i] == target[i])
            {
                continue;
            }
            if(adjmat[source[i]-'a'][target[i]-'a'] == INT_MAX)
            {
                return -1;
            }
            ans+= adjmat[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
    
};