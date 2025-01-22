class Solution {
public:
    string generate(string word)
    {
        vector<int>arr(26,0);
        for(char &ch : word)
        {
            arr[ch-'a']++;// marking frequency in arr
        }
        string new_word = " ";
        // forming the new word by storing the frequency
        for(int i =0;i<arr.size();i++)
        {
            int freq = arr[i];
            if(freq > 0)
            {
                new_word += string(freq, i+'a');
            }
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n = strs.size();
        unordered_map<string , vector<string>>mp;
        vector<vector<string>>res;
        for(int i =0;i<n;i++)
        {
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);   
        }
        for(auto x : mp)
        {
            res.push_back({x.second});
        }
        return res;
        
    }
};