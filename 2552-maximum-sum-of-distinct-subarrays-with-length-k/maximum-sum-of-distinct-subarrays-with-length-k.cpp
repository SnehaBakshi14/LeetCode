class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        long long max_sum = 0;
        long long sum = 0;
        int l=0,r=0;
        unordered_map<int,int> mp;
        while(r < nums.size()){
            mp[nums[r]]++;
            sum += nums[r];
            if(r-l+1 > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                sum -= nums[l];
                l++;
            }
            if(mp.size()==k && (r-l+1)==k) max_sum = max(max_sum,sum);
            r++;
        }
        return max_sum;
    }
};