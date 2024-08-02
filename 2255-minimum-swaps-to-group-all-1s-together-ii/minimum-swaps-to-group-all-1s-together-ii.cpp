class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        // int n = nums.size();
        // vector<int>temp(2*n);
        // for(int i =0;i<2*n;i++)
        // {
        //     temp[i] = nums[i%n]; // for append in circular array
        // }
        // int totalones = accumulate(begin(nums),end(nums),0);
        // int i =0,j=0;
        // int currones =0 ,maxcount =0;
        // while(j<2*n)
        // {
        //     if(temp[j] == 1)
        //     {
        //         currones +=1;
        //     }
        //     if(j-i+1 > totalones)
        //     {
        //         currones -= temp[i];
        //         i++;
        //     }
            
        //     maxcount = max(maxcount ,currones);
        //     j++;
        // }
        // return totalones-maxcount;


        // MODIFIED SPACE COMPLEXITY

         int n = nums.size();
        int totalones = accumulate(begin(nums),end(nums),0);
        int i =0,j=0;
        int currones =0 ,maxcount =0;
        while(j<2*n)
        {
            if(nums[j%n] == 1)
            {
                currones +=1;
            }
            if(j-i+1 > totalones)
            {
                currones -= nums[i%n];
                i++;
            }
            
            maxcount = max(maxcount ,currones);
            j++;
        }
        return totalones-maxcount;
    }
};