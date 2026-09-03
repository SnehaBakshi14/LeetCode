class Solution {
public:
    bool uniformArray(vector<int>& nums1)
    {
        // even - even = even , odd  - odd  = even
        // even - odd = odd , odd  - even = odd
        // If we want to make everything odd, every even number must be greater than the smallest odd number.
        // All-even is possible only when there are no odd numbers.
        // All ODD Possible if: every even number > smallestOdd
        int minOdd = INT_MAX;
        for (int x : nums1) // finding the minimum odd no
        {
            if (x % 2 == 1) 
            {
            minOdd = min(minOdd, x);
            }
        }
        if (minOdd == INT_MAX) return true; // all no are even , no odd no
        // atleast 1 odd no is present
        for (int x : nums1)  // For every even number, we need:even - odd = odd and even - minOdd >= 1
        {
            if (x % 2 == 0 && x <= minOdd)
            {
            return false;
            }
        }
        return true; // all  parity fixed 
    }
};