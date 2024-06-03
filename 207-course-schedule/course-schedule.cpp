class Solution {
public:
    bool CycleCheck(unordered_map<int,vector<int>>&mp,int n,vector<int>&indegree)
    {
        int c=0;// to check if we visit all course
        queue<int>q;
        for(int i =0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                c++;
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int &v :mp[u])
            {
                indegree[v]--;

                if(indegree[v]==0)
                {
                    q.push(v);
                    c++;
                }
            }
        }
        if(c==n)// visited all courses no cycle
        {
            return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>mp;

        for(auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];
            //b -> a;
            mp[b].push_back(a);

            indegree[a]++;
        }

        return CycleCheck(mp,numCourses,indegree);
    }
};