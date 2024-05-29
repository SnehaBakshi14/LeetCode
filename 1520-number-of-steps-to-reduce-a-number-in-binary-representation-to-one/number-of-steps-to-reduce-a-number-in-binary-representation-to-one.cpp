class Solution {
public:
    void addone(string& s)
    {
        // traverse from right to left till 1 st zero reached, keep converting 1 to 0 then convert it(1st zero) to one
        int i = s.length()-1;
        while(i >= 0  && s[i]!= '0')
        {
            s[i] = '0';
            i--;
        }
        if(i<0)
        {
            s = '1'+s;//right sb zero hogye toh
        }
        else
        {
            s[i] = '1';
        }
    }

    int numSteps(string s)
    {
        int op = 0;
        while(s.length()>1)
        {
            int n = s.length();
            if(s[n-1] == '0')
            {
            s.pop_back();// case even divide by zero(pop right most bit)
            }
            else
            {
                addone(s);// case odd add one
            }
            op++;//outside becuase if else dono main increment hoga
        }
        return op;
    }
};