class Solution {
public:
    bool eat_all_bananas(vector<int>& piles, int h,int k){
        long long int hours = 0;
        for(int i=0;i<piles.size();i++){
            int num = piles[i];
            if(num <= k){
                hours++;
            }
            else {
                // hours += (num/k + 1);
                hours += (num + k - 1) / k;
            }
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_k = *max_element(piles.begin(),piles.end());
        int s = 1;
        int e = max_k;
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(eat_all_bananas(piles,h,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};