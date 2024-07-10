class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        // Approach 1 Simulation
        int d = 0;// deptj from main folder
        for(string &log : logs)
        {
            if(log == "../")
            {
                d = max(0,d-1);
            }
            else if(log == "./")
            {
                continue;
            }
            else
            {
                d++;
            }
        }
        return d;
    }
};