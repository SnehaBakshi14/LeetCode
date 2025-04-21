class Solution {
public:
     void DFS(int i,int j,vector<vector<int>>& image,int startcolour,int newcolour , int m ,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=startcolour)
        {
            return;
        }
        image[i][j]=newcolour;

        DFS(i+1,j,image,startcolour,newcolour , m ,n);
        DFS(i-1,j,image,startcolour,newcolour,m,n);
        DFS(i,j+1,image,startcolour,newcolour,m,n);
        DFS(i,j-1,image,startcolour,newcolour,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size();
        int n = image[0].size();
        int startcolor = image[sr][sc];
        
        if(startcolor != color)DFS(sr,sc,image,startcolor,color,m,n);

        return image;

    }
};