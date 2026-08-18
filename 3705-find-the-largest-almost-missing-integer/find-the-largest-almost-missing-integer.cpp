class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        // jo sirf ek subarray main ayega of size k and then usme bhi largest
        //In how many size-k subarrays does this number appear?
        // Suppose a number appears multiple times inside the same subarray.So we are counting subarrays containing the number, not occurrences of the number.

        int n = nums.size();

        // Case 1: k = 1
        if (k == 1) {
            int freq[51] = {0};

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (int x = 0; x <= 50; x++) {
                if (freq[x] == 1) {
                    ans = x;
                }
            }

            return ans;
        }

         // Case 2: k = n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

         // Case 3: 1 < k < n
        int freq[51] = {0};

        for (int x : nums) {
            freq[x]++;
        }

        int ans = -1;

        // Only nums[0] can be almost missing
        if (freq[nums[0]] == 1) {
            ans = nums[0];
        }

        // Only nums[n-1] can be almost missing
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
        
    }
};