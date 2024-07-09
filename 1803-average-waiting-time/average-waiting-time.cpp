class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) 
    {
        int n = customers.size();
        double totalwaitTime = 0;
        int currTime =0;
        for(auto &vec : customers)
        {
            int arrivalTime = vec[0];
            int cooktime = vec[1];
            if(currTime < arrivalTime)// chef idle
            {
                currTime = arrivalTime;
            }
            int waitTime = (currTime+cooktime)-arrivalTime;
            totalwaitTime += waitTime;
            currTime +=cooktime;
        }
        return totalwaitTime/n;
    }
};