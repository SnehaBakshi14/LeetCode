class Solution {
public:
    int countCommas(int n) 
    {
        return n<1000 ? 0:(n-1000)+1;
        // or n-999
        // max range is 10^5 which will have only 1 comma so we need to count just how many numbers are there in range betwwwn 1000 to n and add comma count;         
    }
};