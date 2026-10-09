class Solution {
public:
    int minInsertions(string s) 
    {
        int n = s.length();
        int cnt =0;// track of open brackets
        int res =0;// track of no of insertions
        int i =0;
        while(i<n)
        {
            if(s[i] == '(')
            {
                cnt++;
                i++;
            }
           else
           {
               // ) closing bracket
               if(cnt > 0)
               {
                   cnt--; // for balancing
               }
                else
                {
                    res++ ; // we need to add one opening bracket if no opening bracket present hence +1 
            }
                
                if((i+1) < n && s[i+1] == ')') // to check if valid
                {
                i += 2;
                }
                else
                {
                res += 1 ;// adding a closing bracket to make  valid 
                i++;
                }
            }
        }
                
            return res + (2*cnt); // adding clsing bracket with respect to opening brackets
       
    }
};