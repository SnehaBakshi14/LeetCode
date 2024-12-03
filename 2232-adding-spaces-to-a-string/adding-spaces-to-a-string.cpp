class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        int m = s.size();
        int n = spaces.size();
        int j =0;
        string res = "";
        for(int i =0;i<m;i++)
        {
            if(j<n && i == spaces[j])
            {
                res+= " ";
                j++;
            }
            res += s[i];
        }
        return res;
    }
};