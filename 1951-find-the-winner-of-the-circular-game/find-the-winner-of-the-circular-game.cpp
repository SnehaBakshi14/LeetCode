class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        //Approach 1 simulation with array
        vector<int>arr;
        for(int i =1;i<=n;i++)
        {
            arr.push_back(i);// Putting elements in circle
        }
        int i =0;// game starts from 1st player who is sitting at 0th index in arr
        while(arr.size() > 1)//till 1 friend is left
        {
            int idx = (i + k -1) % arr.size();
            arr.erase(arr.begin() + idx);
            i = idx;
        }
        return arr[0];
    }
};