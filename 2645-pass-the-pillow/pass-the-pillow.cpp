class Solution {
public:
    int passThePillow(int n, int time) 
    {
        //Approach 1 simulation
        int idx = 1;
        int dir = 1;// left to right = 1,right to left = -1
        while(time>0)
        {
            if(idx+dir >=1 && idx+dir<=n)
            {
                idx += dir;
                time--;
            }
            else
            {
                dir *= -1;// compliments the sign when out of boundary
            }
        }
        return idx;
        
    }
};