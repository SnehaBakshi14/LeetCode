class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        // Approach 1 Simulation
        // int d = 0;// depth from main folder
        // for(string &log : logs)
        // {
        //     if(log == "../")
        //     {
        //         d = max(0,d-1);
        //     }
        //     else if(log == "./")
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         d++;
        //     }
        // }
        // return d;

        // Approach 2 stack 
        stack<string>st;
        for(string &log : logs)
        {
            if(log == "../")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(log != "./")
            {
                st.push(log);
            }
        }
        return st.size();
    }
};