// class KthLargest {
// public:
//     int K;
//     priority_queue<int , vector<int>,greater<int>>pq;// min heap

//     KthLargest(int k, vector<int>& nums)
//     {
//         K = k;
//         for(int &num : nums)
//         {
//             pq.push(num);
//         }
//         if (pq.size() > k)
//         {
//             pq.pop();// min element will be popped
//         }
//     }
//     int add(int val) 
//     {
//         pq.push(val);
//         if(pq.size() > K)
//         {
//             pq.pop();
//         }
//         return pq.top();
//     }
// };
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */