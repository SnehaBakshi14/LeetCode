class Solution {
public:
    int getmindays(vector<int>& weights, int cap)
    {
        int days = 1;
        int load = 0;
        for(int i = 0;i<weights.size();i++)
        {
            if(load + weights[i] > cap)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high)
        {
            int mid = (low+high)/2;
           int  mindays = getmindays(weights,mid);
            if(mindays <= days )
            {
                // possible
                // try to find min capacity
                high = mid-1;
            }
            else
            {
                // not possible
                low = mid+1;
            }
        }
        return low;
    }
};