class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int z =0,one =0;
        int n = nums.size();
        for(int n:nums)
        {
            if(n == 0)
            z++;
            else if ( n == 1)
            one++;
        }
        for(int i = 0;i < z;++i)
        {
            nums[i] = 0;
        }
        for(int i = z;i < z+one;++i)
        {
            nums[i] = 1;
        }
        for(int i = z+one ;i <n;++i)
        {
            nums[i] = 2;
        }
        
    }
};