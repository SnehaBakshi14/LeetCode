class Solution {
public:
int getCount(int num, unordered_map<int, int>& freqMap) {
        // Get the sum of counts of numbers within 2 of `num`
        return freqMap[num] +
               freqMap[num - 1] +
               freqMap[num + 1] +
               freqMap[num - 2] +
               freqMap[num + 2];
    }
    long long continuousSubarrays(vector<int>& nums) 
    {
         int n = nums.size();
        int j = 0;  // Left pointer of the sliding window
        long cnt = 0;  // Count of valid subarrays

        unordered_map<int, int> freqMap;  // Frequency map to track counts of elements

        for (int i = 0; i < n; i++) {
            // Increment the count for the current number in the map
            freqMap[nums[i]]++;

            // Shrink the window if the current window is invalid
            while ((i - j + 1) > getCount(nums[i], freqMap)) {
                freqMap[nums[j]]--;  // Decrement the count for nums[j]
                if (freqMap[nums[j]] == 0) {
                    freqMap.erase(nums[j]);  // Remove if the count becomes zero
                }
                j++;  // Move the left pointer
            }

            // Add the size of the valid window to the result
            cnt += (i - j + 1);
        }

        return cnt;
        
    }
};