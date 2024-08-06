class Solution {
public:
    int minimumPushes(string word)
    {
        vector<int>mp(26,0);
        for(char&ch : word)
        {
            mp[ch-'a']++;

        }
        int res =0;
        sort(begin(mp),end(mp),greater<int>());// descending order of freq
        for(int i =0;i<26;i++)
        {
            int freq = mp[i];
            int press = (i/8 + 1);
             res += press * freq;
        }
        return res;
        
    }
};