class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<int>skip;// length to not be reversed
        string result;
        for(char &ch: s)
        {
            if(ch == '(')
            {
                skip.push(result.length());
            }
            else if(ch == ')')
            {
                int l = skip.top();
                skip.pop();
                reverse(begin(result)+l,end(result));
            }
            else
            {
                result.push_back(ch);
            }
        }
         return result;
    }
};