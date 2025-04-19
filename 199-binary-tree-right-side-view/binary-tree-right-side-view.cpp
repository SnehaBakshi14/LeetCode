/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void giverightview(TreeNode* root , int level , int& maxlevel , vector<int>& res)
    {
      
        if(root == NULL)
        {
            return ;
        }
        if(level > maxlevel)
        {
            res.push_back(root->val);
            maxlevel = level;
        }
        giverightview(root->right , level+1 ,maxlevel ,res);
        giverightview(root->left , level+1 ,maxlevel ,res);

    }
    vector<int> rightSideView(TreeNode* root) 
    {
        int level = 0;
        int maxlevel = -1;
        vector<int>ans;
         giverightview(root,level,maxlevel,ans);
        return ans;
        
    }
};