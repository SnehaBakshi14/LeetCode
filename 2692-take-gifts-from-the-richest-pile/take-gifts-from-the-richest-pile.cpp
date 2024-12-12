class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        for (int i = 0; i < k && maxHeap.top() > 1; i++) {
            int x = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(floor(sqrt(x)));
        }
        long sum = 0;
        while (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return sum;
        
    }
};