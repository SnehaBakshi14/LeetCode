class Solution {
public:
// Approach 1 
    // void addone(string& s)
    // {
    //     // traverse from right to left till 1 st zero reached, keep converting 1 to 0 then convert it(1st zero) to one
    //     int i = s.length()-1;
    //     while(i >= 0  && s[i]!= '0')
    //     {
    //         s[i] = '0';
    //         i--;
    //     }
    //     if(i<0)
    //     {
    //         s = '1'+s;//right sb zero hogye toh
    //     }
    //     else
    //     {
    //         s[i] = '1';
    //     }
    // }

    // int numSteps(string s)
    // {
    //     int op = 0;
    //     while(s.length()>1)
    //     {
    //         int n = s.length();
    //         if(s[n-1] == '0')
    //         {
    //         s.pop_back();// case even divide by zero(pop right most bit)
    //         }
    //         else
    //         {
    //             addone(s);// case odd add one
    //         }
    //         op++;//outside becuase if else dono main increment hoga
    //     }
    //     return op;
    // }

    // Approach 2 carry 
     int numSteps(string s)
    {
        int n = s.length();
        int op =0;
        int carry= 0;
        for(int i =n-1;i >=1; i--)
        {
            if(((s[i]-'0')+carry) % 2 == 1) // odd 
            {
                op += 2;
                carry = 1;
            }
            else
            {
                op += 1;// even;
            }
        }
        return op+carry;// last main i zero pe hoga toh last operation reh jayega so add carry
    }
};