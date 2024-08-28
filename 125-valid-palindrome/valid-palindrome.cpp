class Solution {
public:
    bool checker(char ch){
        return (ch>='A' && ch<='Z');
    }
    bool alpha(char ch){
        return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch >= '0' && ch <= '9');
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(!alpha(s[i]))i++;
            else if(!alpha(s[j]))j--;

            else{
                char ch1 = s[i++];
                if(checker(ch1)) {
                    ch1 += 32;
                }
                char ch2 = s[j--];
                if(checker(ch2)){
                    ch2 += 32;
                }
                if(ch1 != ch2) return false;
            }
        }
        return true;
    }
};