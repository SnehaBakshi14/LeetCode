class Solution {
public:
    int sumCounts(vector<int>& nums) 
    {
        const int MOD = 1000000007;
        int n = nums.size();
        long long total_sum = 0;

        for (int i = 0; i < n; ++i) {
            // visited array sized to max element value (100)
            std::vector<bool> seen(101, false);
            int distinct_count = 0;

            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    distinct_count++;
                }
                total_sum = (total_sum + 1LL * distinct_count * distinct_count) % MOD;
            }
        }

        return total_sum;
        
    }
};