/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>parent;
    void inOrder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        if(root->left != NULL)
        {
            parent[root->left] = root;
        }
        inOrder(root->left);
        if(root->right != NULL)
        {
            parent[root->right] = root;
        }
        inOrder(root->right);
    }
    void BFS(TreeNode* target, int k ,vector<int>& res)
    {
        queue<TreeNode*>que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        while(!que.empty())
        {
            int n = que.size();
            if(k == 0)
            {
                break;
            }
            while(n--)
            {
                    TreeNode* curr = que.front();
                    que.pop();

                    // left
                    if(curr->left != NULL && !visited.count(curr->left->val))
                    {
                        que.push(curr->left);
                        visited.insert(curr->left->val);
                    }
                    // right
                    if(curr->right != NULL && !visited.count(curr->right->val))
                    {
                        que.push(curr->right);
                        visited.insert(curr->right->val);
                    }
                    //parent
                    if(parent.count(curr) && !visited.count(parent[curr]->val))
                    {
                        que.push(parent[curr]);
                        visited.insert(parent[curr]->val);
                    }
            }
            k--;
        }
        while(!que.empty())
        {
            TreeNode* temp = que.front();
            que.pop();
            res.push_back(temp->val);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int>res;
        inOrder(root);
        BFS(target,k,res);
        return res;

    }
};