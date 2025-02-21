class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int i = n-1,j=m-1;
        string res;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += num1[i--] - '0';
            }
            if(j>=0){
                carry += num2[j--] - '0';
            }
            res += to_string(carry % 10);
            carry /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};