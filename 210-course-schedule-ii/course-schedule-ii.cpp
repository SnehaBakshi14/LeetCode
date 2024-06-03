class Solution {
public:

    vector<int> CycleCheck(unordered_map<int,vector<int>>&mp,int n,vector<int>&indegree)
    {
        vector<int> result;
        int c=0;// to check if we visit all course
        queue<int>q;
        for(int i =0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                c++;
                result.push_back(i);
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
                    result.push_back(v);
                }
            }
        }
        if(c==n)// visited all courses no cycle
        {
            return result;
        }
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>mp;
        //vector<int> result;
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