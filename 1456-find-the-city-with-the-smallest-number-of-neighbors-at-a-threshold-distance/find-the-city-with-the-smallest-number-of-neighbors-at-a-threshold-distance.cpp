class Solution {
public:
# define P pair<int,int>
    void dijkstra(int n , unordered_map<int,vector<P>>&adj,vector<int>&result,int s)
    {
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,s});
        fill(result.begin(),result.end(),INT_MAX);
        result[s]=0;
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &p : adj[node])
            {
                int adjnode = p.first;
                int dist = p.second;
                if(d+dist < result[adjnode])
                {
                    result[adjnode] = d+dist;
                    pq.push({d+dist , adjnode});
                }
            }
        }
    }
    int findresultcity(int n,vector<vector<int>>SPM,int d)
    {
        int resultcity = -1;
        int leastreachcount = INT_MAX;
        for(int i =0;i<n;i++)
        {
            int countreachable = 0;
            for(int j =0;j<n;j++)
            {
                if(i!=j && SPM[i][j] <= d)
                {
                    countreachable++;
                }
            }
            if(countreachable <= leastreachcount)
            {
                 leastreachcount = countreachable;
                 resultcity = i;
            }
        }
        return resultcity;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>>SPM(n,vector<int>(n,1e9+7));
        for(int i =0;i<n;i++)
        {
            SPM[i][i] = 0;
        }
        unordered_map<int,vector<P>>adj;
        for(auto&edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        for(int i =0;i<n;i++)
        {
            dijkstra(n,adj,SPM[i],i);
        }
        return findresultcity(n,SPM,distanceThreshold);
        
    }
};