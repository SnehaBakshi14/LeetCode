class Solution {
public:
    int n;
    int m;
    void DFS(int i,int j,vector<vector<int>>& image,int startcolour,int newcolour)
    {
        if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=startcolour)
        {
            return;
        }
        image[i][j]=newcolour;

        DFS(i+1,j,image,startcolour,newcolour);
        DFS(i-1,j,image,startcolour,newcolour);
        DFS(i,j+1,image,startcolour,newcolour);
        DFS(i,j-1,image,startcolour,newcolour);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor)
     {
         m= image.size();
         n = image[0].size();
        int startcolour = image[sr][sc];
        if(startcolour != newcolor)
        {
            DFS(sr,sc,image,startcolour,newcolor);
        }
        return image;
    }
};

// class Solution {
// public:
//     int m,n;
//     void dfs(int i,int j,vector<vector<int>>& mat,int startcolor,int newcolor){
//         if(i<0 || j<0 || i>=m || j>=n || mat[i][j] != startcolor){
//             return;
//         }
//         mat[i][j] = newcolor;

//         dfs(i+1,j,mat,startcolor,newcolor);
//         dfs(i-1,j,mat,startcolor,newcolor);
//         dfs(i,j+1,mat,startcolor,newcolor);
//         dfs(i,j-1,mat,startcolor,newcolor);
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int newcolor) {
//         m = mat.size();
//         n = mat[0].size();

//         int startcolor = mat[sr][sc];

//         if(startcolor != newcolor)dfs(sr,sc,mat,startcolor,newcolor);

//         return mat;
//     }
// };