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
 
// After my last implementation, I figured I'd look at expected ways of handling this problem.
// Turns out, in-order recursion is the expected approach--but worse on space because of our vector
class Solution {
public:
    vector<int> v;
    void inOrder(TreeNode* root)
    {
        if (root == NULL) {
            return;
        }
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        int mn = INT_MAX;

        for (int i = 1; i < v.size(); i++) {
            mn = min(mn, v[i]-v[i-1]);
        }
        return mn;
    }
};