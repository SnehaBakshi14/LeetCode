class Solution {
public:
    string maxSumOfSquares(int num, int sum)
    {
        if(sum > num * 9)
        {
            return ""; // if we put 9 in each place and still sum is greater 
        }
        int nines = sum/9;
        int remain = sum%9;
        string res(nines , '9');// add highest 9 to make the sum largest
        if(remain > 0)
        {
            res.push_back(remain + '0'); // add remaing in the string
        }
        res.append(num - res.length() ,'0'); // in the remaining places to complete n digits we put 0
        return res;
    }
};