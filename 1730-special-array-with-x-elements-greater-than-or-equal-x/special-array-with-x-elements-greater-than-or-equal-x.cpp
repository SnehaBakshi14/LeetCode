class Solution {
public:
    //Approach 1 for + binary serach
    // int specialArray(vector<int>& nums) {
    //     sort(begin(nums), end(nums));
    //     int n = nums.size();

    //     for(int x = 0; x <=n; x++) {
            
    //         int i = lower_bound(begin(nums), end(nums), x) - begin(nums);

    //         if(n-i == x) {
    //             return x;
    //         }
    //     }

    //     return -1;
    // }

    // Approach 2 x pr bhi binary search lga do

    int specialArray(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int n = nums.size();

        int l =0,r=n;
        while(l<=r)
        {
            int  midx = l+(r-l)/2;
            int idx = lower_bound(begin(nums),end(nums),midx)-begin(nums);
            //1st element >= midx
            int count = n - idx;
            if(count == midx)
            {
                return midx;
            }
            else if(count <= midx)
            {
                r = midx-1;
            }
            else
            {
                l = midx+1;
            }
        }
        return -1;
    }
};