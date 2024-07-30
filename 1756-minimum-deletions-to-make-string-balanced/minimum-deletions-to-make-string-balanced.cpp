class Solution {
public:
    int minimumDeletions(string s)
    {
        // Approach 1 using stack
        // int n = s.length();
        // int count =0;
        // stack<char>st;
        // for(int i =0;i<n;i++)
        // {
        //     if(!st.empty() && s[i] == 'a' && st.top()=='b')
        //     {
        //         st.pop();
        //         count++;
        //     }
        //     else
        //     {
        //         st.push(s[i]);
        //     }
        // }
        // return count;

        // Approach 2 using bcount and acount
        // int n = s.length();
        // vector<int>right_a(n,0);// to keep count of no of a in right of every index
        
        // int acount =0;
        // for(int i =n-1;i>=0;i--)// right traversal
        // {
        //     right_a[i] = acount;
        //     if(s[i] == 'a')
        //     {
        //         acount++;
        //     }
        // }
        // int count = INT_MAX;
        // int bcount =0;
        // for(int i =0;i<n;i++)
        // {
        //     count = min(count , bcount+right_a[i]);
        //     if(s[i] == 'b')
        //     {
        //         bcount++;
        //     }
        // }
        // return count;

        // Approach 3
         int n = s.length();
        int acount =0;
        for(int i =n-1;i>=0;i--)// right traversal
        {
            if(s[i] == 'a')
            {
                acount++;
            }
        }
        int count = INT_MAX;
        int bcount =0;
        for(int i =0;i<n;i++)
        {
            if(s[i] == 'a')
            {
                acount--;
            }
            count = min(count , bcount+acount);
            if(s[i] == 'b')
            {
                bcount++;
            }
        }
        return count;

    }
};