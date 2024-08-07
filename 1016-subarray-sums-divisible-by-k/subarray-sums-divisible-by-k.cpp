class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = 1;
        int sum = 0,ans = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int r = sum % k;
            if(r<0)
            {
                r+=k;
            }
            if(m.find(r) != m.end()){
                ans += m[r];
            }
            m[r]++;
        }
        return ans;
    }
};