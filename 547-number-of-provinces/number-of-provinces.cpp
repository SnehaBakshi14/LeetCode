class Solution {
public:
    void DFS(unordered_map<int,vector<int>>&mp,int u,vector<bool>&visited)
    {
        visited[u] = true;
        for(int &v : mp[u])//Discover neighbour
        {
            if(!visited[v])
            {
                DFS(mp,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        unordered_map<int,vector<int>> mp;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            
            }
        }
        
        vector<bool> visited(n,false);
        int c= 0;
        for(int i =0;i<n;i++)
        {
            if(!visited[i])
            {
                c++;
                DFS(mp,i,visited);// ek dfs call main ek province complete ho jayega
            }
        }
        return c;


    // void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
    //     visited[u] = true;
        
    //     //Visit neighbours
    //     for(int &v : adj[u]) {
    //         if(!visited[v]) {
    //             dfs(adj, v, visited);
    //         }
    //     }
    // }
    
    
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();
        
    //     unordered_map<int, vector<int>> adj;
        
    //     for(int i = 0; i<n; i++) {
    //         for(int j = 0; j<n; j++) {
    //             if(isConnected[i][j] == 1) {
    //                 adj[i].push_back(j);
    //                 adj[j].push_back(i);
    //             }
    //         }
    //     }
        
    //     vector<bool> visited(n, false);
    //     int count = 0;
        
    //     for(int i = 0; i<n; i++) {
    //         if(!visited[i]) {
    //             count++;
    //             dfs(adj, i, visited);
    //         }
    //     }
        
    //     return count;
    }
};