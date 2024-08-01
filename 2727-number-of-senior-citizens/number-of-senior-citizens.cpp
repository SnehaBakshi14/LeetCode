class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int count =0;
        int n = details.size();
        // for(string &vec : details)
        // {
        //     char a = vec[11];
        //     char b = vec[12];
        //     if( a > '6' || (a == '6' && b > '0'))
        //     {
        //         count++;
        //     }
        // }
        for(auto &vec : details)
        {
            int age = stoi(vec.substr(11,2));
            if(age > 60)
            {
                count++;
            }
        }
        return count;
    }
};