class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int>count(26);
        int n = magazine.size();
        for(int i =0;i<n;i++)
        {
            count[magazine[i] - 'a']++;
        }
        int m = ransomNote.size();
        for(int i =0;i<m;i++)
        {
            if(count[ransomNote[i] - 'a'] > 0)
            {
                count[ransomNote[i] - 'a']--;
            }
            else
            {
                return false;
            }
        }
       return true;
    }
};