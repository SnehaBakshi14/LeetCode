class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.length();
        int open =0;
        int close =0;
        int res = 0;
        for(int i =0;i<n;i++) // left to right
        {
            if(s[i] == '(')
            {
                open += 1;
            }
            else
            {
                close +=1;
            }

            if(open == close)
            {
                res = max(res , open+close);
            }
            else if(close > open)
            {
                open = close =0;
            }
        }
        open =0;
        close =0;
        for(int i =n-1;i>=0;i--) // right to left
        {
            if(s[i] == '(')
            {
                open += 1;
            }
            else
            {
                close +=1;
            }

            if(open == close)
            {
                res = max(res , open+close);
            }
            else if(open > close)
            {
                open = close =0;
            }
        }
        return res;
    }
};