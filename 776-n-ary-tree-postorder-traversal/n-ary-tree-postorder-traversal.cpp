/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(vector<int>&ans,Node*root)
    {
        if(!root)
        {
            return ;
        }
        for(Node* child:root->children)
        {
            dfs(ans,child);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root)
    {
        vector<int>ans;
        dfs(ans,root);
        return ans;
        
    }
};