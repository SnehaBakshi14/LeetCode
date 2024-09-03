class Solution {
public:
    int getLucky(string s, int k) 
    {
        string res = "";
        for(char &ch :s)
        {
            int x = ch-'a'+1; 
            res += to_string(x);
        }
        int sum =0;
        while(k--)
        {
            sum =0;
            for(char &ch : res)
            {
                sum += ch-'0';
            }
            res = to_string(sum);

        }
        return stoi(res);
    }
};