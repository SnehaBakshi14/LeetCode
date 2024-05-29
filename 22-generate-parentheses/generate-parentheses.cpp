class Solution {
public:
// Approch 1 Normal Recursion
    //  vector<string> result;

    // bool isValid(string str)
    // {
    //     // For string to be valid overall sum should be zero
    //     int c = 0;
    //     for(char ch : str)
    //     {
    //         if(ch == '(')
    //             c++;
    //         else
    //          c--;
    //         if(c<0)
    //         {
    //             return false;
    //         }
    //     }
    //     return c==0;

    // }


    // void solve(string&curr, int n)
    // {
    //     if(curr.length() == 2*n)
    //     {
    //         if(isValid(curr))
    //         {
    //             result.push_back(curr);
    //         }
    //          return;
    //     }
    //     curr.push_back('(');//do
    //     solve(curr,n);//explore
    //     curr.pop_back();//undo

    //     curr.push_back(')');//do
    //     solve(curr,n);//explore
    //     curr.pop_back();//undo
    // }

    // vector<string> generateParenthesis(int n)
    // {
    //     string curr = "";

    //     solve(curr,n);
        
    //     return result;
    // }


// Approach 2 Smart recursion
     vector<string> result;

    void solve(string&curr, int n , int open ,int close)
    {
        if(curr.length() == 2*n)
        {
                result.push_back(curr);  
                return;
        }  
        if(open < n)
        {
        curr.push_back('(');//do
        solve(curr,n,open+1,close);//explore
        curr.pop_back();//undo
        }
        if(close < open)
        {
        curr.push_back(')');//do
        solve(curr,n,open,close+1);//explore
        curr.pop_back();//undo
        }
    }
     vector<string> generateParenthesis(int n)
    {
        string curr = "";
        int open =0;int close=0;
        solve(curr,n ,open,close);
        
        return result;
    }

};

