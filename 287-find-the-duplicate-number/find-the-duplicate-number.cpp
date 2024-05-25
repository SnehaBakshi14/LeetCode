class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> freq(n+1,0);
        // for(int &it : nums){
        //     freq[it]++;
        //     if(freq[it] == 2){
        //         return it;
        //     }
        // }
        // return 0;

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);

        slow = nums[0];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;

    }
};