class Solution {
public:
int n;
int width;
int t[1001][1001];
    int solve(vector<vector<int>>& books,int i ,int remw,int maxht)
    {
        if(i >= n)
        {
            return maxht;
        }
        if(t[i][remw] != -1)
        {
            return t[i][remw];
        }
        int bookw = books[i][0];
        int bookh = books[i][1];
        int keep = INT_MAX;
        int skip = INT_MAX;

        // keep
        if(bookw <= remw)
        {
            keep = solve(books,i+1, remw-bookw, max(maxht,bookh));
        }
        // skip and placed in new next shelf
        skip = maxht + solve(books, i+1,width - bookw , bookh);

       return  t[i][remw] = min(keep ,skip);
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        memset(t,-1,sizeof(t));
        width = shelfWidth;
        n = books.size();
        int remw = shelfWidth;
        return solve(books,0,remw,0);
    }
};