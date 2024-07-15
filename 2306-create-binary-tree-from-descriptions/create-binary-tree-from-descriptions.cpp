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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int,TreeNode*>mp;//value with corresponding node
        unordered_set<int>childset;// to find root node
        for(vector<int>&vec:descriptions)
        {
            int parent =vec[0];
            int child =vec[1];
            int isLeft =vec[2];
        if(mp.find(parent) == mp.end())// does not exsist
        {
            mp[parent] = new TreeNode(parent);// create node
        }
         if(mp.find(child) == mp.end())// does not exsist
        {
            mp[child] = new TreeNode(child);// create node
        }
        if(isLeft == 1)// left child
        {
            mp[parent]->left = mp[child];
        }
        else
        {
            mp[parent]->right = mp[child];
        }
        childset.insert(child);
       }
    for(vector<int>&vec:descriptions)
    {
            int parent =vec[0];
            if(childset.find(parent) == childset.end())
            {
                return mp[parent];
            }
    }
    return NULL;
    }
};