class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len =0;
        int n = s.length();
        int l =0,r=0;
        int maxlen = 0;
        vector<int>hash(256,-1);
        while(r < n)
        {
            if(hash[s[r]] != -1)
            {
                // in the map 
                if(hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            len = r-l+1;
            maxlen = max(maxlen , len);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};