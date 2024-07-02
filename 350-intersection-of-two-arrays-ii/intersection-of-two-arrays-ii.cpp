class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        // Approach 1 map 
            // unordered_map<int,int>mp;
            // for(int&num : nums1)
            // {
            //     mp[num]++;
            // }
            // vector<int>result;
            // for(int i =0;i<nums2.size();i++)
            // {
            //     int n = nums2[i];
            //     if(mp[n] > 0)
            //     {
            //         mp[n]--;
            //         result.push_back(n);
            //     }
            // }
            // return result;


        // Approach 2
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int i =0;//nums1
        int j =0;//nums2
        vector<int>res;
        while( i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
            
        }
        return res;
    }
};