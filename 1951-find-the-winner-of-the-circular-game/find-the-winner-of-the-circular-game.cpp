class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        //Approach 1 simulation with array
        // vector<int>arr;
        // for(int i =1;i<=n;i++)
        // {
        //     arr.push_back(i);// Putting elements in circle
        // }
        // int i =0;// game starts from 1st player who is sitting at 0th index in arr
        // while(arr.size() > 1)//till 1 friend is left
        // {
        //     int idx = (i + k -1) % arr.size();
        //     arr.erase(arr.begin() + idx);
        //     i = idx;
        // }
        // return arr[0];


        // Approach 2 Queue simulation
        queue<int> q;
        for(int i =1 ;i<=n;i++)
        {
            q.push(i);
        }
        while(q.size() > 1)
        {
            for(int count =1;count<=k-1;count++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};