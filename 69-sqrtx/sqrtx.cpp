class Solution {
public:
    int mySqrt(int x) 
    {
     int low = 1;
     int high = x;
     int res = 0;
     while(low<= high)
     {
        int mid = low + (high - low) / 2;
        long long square =  1ll *mid*mid;
        if(square <= x)
        {
            res = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
     }
     return res;
    }
};