class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int l1 = s.length();
        int l2 = t.length();
        int i =0;
        int j =0;
        while(i<l1 && j<l2)
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return l2-j;
        
    }
};