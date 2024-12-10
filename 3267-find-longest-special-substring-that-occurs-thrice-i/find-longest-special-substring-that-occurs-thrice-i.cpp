class Solution {
public:
    int maximumLength(string s) 
    {
         int n = s.size();
        if (n < 3) return -1;

        int maxi = -1;
        unordered_map<string, int> freq;

        // Iterate over possible lengths of substrings
        for (int len = 1; len <= n; len++) {
            freq.clear();
            int count = 1;

            // Check sliding window substrings of length `len`
            for (int i = 0; i + len <= n; i++) {
                string sub = s.substr(i, len);
                
                // Check if the substring is made of a single repeating character
                bool isValid = true;
                for (char c : sub) {
                    if (c != sub[0]) {
                        isValid = false;
                        break;
                    }
                }
                
                if (isValid) {
                    freq[sub]++;
                    if (freq[sub] >= 3) {
                        maxi = max(maxi, len);
                    }
                }
            }
        }
        return maxi;
    }
};