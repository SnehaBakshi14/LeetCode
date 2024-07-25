class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    { // Using count sort
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int & n : nums)
        {
            mp[n]++;// freq of every character
        }
        int maxi = *max_element(begin(nums),end(nums));
        int mini = *min_element(begin(nums),end(nums));
        int i =0;
        for(int n = mini; n<=maxi ; n++)
        {
            while(mp[n] > 0)
            {
                nums[i] = n;
                i++;
                mp[n]--;
            }

        }
        return nums;
    }
};