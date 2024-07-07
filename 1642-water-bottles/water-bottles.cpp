class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
    //     // Approavh 1 Simulation
    //     int consumed = 0;
    //     while(numBottles >= numExchange)
    //     {
    //         consumed += numExchange;
    //         numBottles -= numExchange;

    //         numBottles += 1;// because of every set consumed we gain a full bottle

    //     }
    //     return numBottles+consumed;// can consume the reamining full bottles also


    // Approach 2 TC = O(1)
    return numBottles + (numBottles - 1)/(numExchange-1);
     }

    
};