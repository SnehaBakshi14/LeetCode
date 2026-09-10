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
    int res;
    pair<int,int>solve(TreeNode* root)
    {
        if(!root)
        {
            return{0,0};
        }
        auto p1 = solve(root->right);
        auto p2 = solve(root->left);
        int totalsum = p1.first+p2.first+root->val;
        int totalcnt = p1.second+p2.second+1;
        int avg = totalsum/totalcnt;
        if(avg == root->val)
        {
            res +=1 ;
        }
    
        return{totalsum,totalcnt};
    }
    int averageOfSubtree(TreeNode* root) 
    {
        // Traversing from leaf node to top node sharing {sum,cnt} of both left and right child;
        res = 0;
        solve(root);
        return res;
        // TC O(n) traversing each node only once
        
    }
};