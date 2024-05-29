class Solution {
public:
     vector<string> result;

    bool isValid(string str)
    {
        // For string to be valid overall sum should be zero
        int c = 0;
        for(char ch : str)
        {
            if(ch == '(')
                c++;
            else
             c--;
            if(c<0)
            {
                return false;
            }
        }
        return c==0;

    }


    void solve(string&curr, int n)
    {
        if(curr.length() == 2*n)
        {
            if(isValid(curr))
            {
                result.push_back(curr);
            }
             return;
        }
        curr.push_back('(');//do
        solve(curr,n);//explore
        curr.pop_back();//undo

        curr.push_back(')');//do
        solve(curr,n);//explore
        curr.pop_back();//undo


    }

    vector<string> generateParenthesis(int n)
    {
        string curr = "";

        solve(curr,n);
        
        return result;
    }
};



// class Solution {
// public:
//     vector<string> result;

//     bool isValid(string str) {
//         int count = 0;

//         for(char ch:str) {
//             if(ch == '(')
//                 count++;
//             else
//                 count--;
//             if(count < 0)
//                 return false;
//         }
//         return count==0;
//     }

//     void solve(string& curr, int n) {
//         if(curr.length() == 2*n) {
//             if(isValid(curr)) {
//                 result.push_back(curr);
//             }
//             return;
//         }

//         curr.push_back('(');
//         solve(curr, n);
//         curr.pop_back();

//         curr.push_back(')');
//         solve(curr, n);
//         curr.pop_back();
//     }

//     vector<string> generateParenthesis(int n) {
//         string curr = "";

//         solve(curr, n);

//         return result;
//     }
// };

