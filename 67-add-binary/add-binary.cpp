class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res ;
        int n = a.size();
        int m = b.size();
        int i=n-1,j=m-1;
        while(i>=0 || j>=0 || carry){
            int sum = 0;
            if(i>=0){
                carry += (a[i--]=='1')?1:0;
            }
            if(j>=0){
                carry += (b[j--]=='1')?1:0;
            }
            res = to_string(carry%2 ) + res;
            carry /= 2;
        }
        return res;
    }
};