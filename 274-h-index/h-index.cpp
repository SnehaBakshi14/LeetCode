class Solution {
public:
    int hIndex(vector<int>& arr) {
        vector<int> bucket(5001,0);
        int n = arr.size();
        int total = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > n){
                bucket[n]++;
            }
            else{
                bucket[arr[i]]++;
            }
        }
        for(int i=n;i>=0;i--){
            total += bucket[i];
            if(total >= i){
                return i;
            }
        }
        return n;
    }
};