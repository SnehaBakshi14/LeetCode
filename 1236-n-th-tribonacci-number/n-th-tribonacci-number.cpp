class Solution {
public:
    int tribonacci(int n) {
        // Optimal Appraoch

        // vector<int> tribo(38,0);
        // tribo[0] = 0;
        // tribo[1] = 1;
        // tribo[2] = 1;

        // for(int i=3;i<=n;i++)
        // {
        //     tribo[i] = tribo[i-1] + tribo[i-2] + tribo[i-3];
        // }
        // return tribo[n];

        // Approach 2

        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        int first = 0,second = 1,third = 1;
        int sum = 0;
        for(int i=3;i<=n;i++){
            sum = first+second+third;
            first = second;
            second = third;
            third = sum;
        }
        return sum;
    }
};