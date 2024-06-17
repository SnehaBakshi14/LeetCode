class Solution {
public:
    typedef long long ll;
    bool judgeSquareSum(int c) 
    {
        //Approach 1
        // for(ll a =0; a*a<=c;a++)
        // {
        //     ll b = sqrt(c-a*a);
        //     if(b*b == c-a*a)
        //     {
        //         return true;
        //     }
        // }
        // return false;

        //Approach 2 two pointer
        ll b = sqrt(c);
        ll a =0;
        while(a<=b)
        {
            ll ans = a*a+b*b;
            if(ans == c)
            return true;
            else if(ans<c)
            a++;
            else
            b--;
        }
        return false;
    }
};