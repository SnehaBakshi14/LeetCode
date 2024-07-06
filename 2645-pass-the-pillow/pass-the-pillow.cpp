class Solution {
public:
    int passThePillow(int n, int time) 
    {
        //Approach 1 simulation
        // int idx = 1;
        // int dir = 1;// left to right = 1,right to left = -1
        // while(time>0)
        // {
        //     if(idx+dir >=1 && idx+dir<=n)
        //     {
        //         idx += dir;
        //         time--;
        //     }
        //     else
        //     {
        //         dir *= -1;// compliments the sign when out of boundary
        //     }
        // }
        // return idx;

        //Approach 2
        int fullround = time/(n-1);
        int timeleft = time%(n-1);
        if(fullround %2 == 0)
        {
            // even
            return timeleft+1;
        }
        else
        {
            // odd 
            return (n - timeleft);// reverse se pass 
        }
        
    }
};