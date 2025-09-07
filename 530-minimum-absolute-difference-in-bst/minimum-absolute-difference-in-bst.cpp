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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prevNode = nullptr; // for keeping track of the previously visited node
        int minDif = INT_MAX;

        while (curr) {
            if (curr->left == nullptr) {
                // Process current node
                if (prevNode) {
                    minDif = std::min(minDif, curr->val - prevNode->val);
                }
                
                // Iterate right path
                prevNode = curr;
                curr = curr->right;

            } else {
                // Essentially, find the rightmost in the current left path
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) { 
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;

                    if (prevNode) {
                        minDif = std::min(minDif, curr->val - prevNode->val);
                    }
                    
                    prevNode = curr;
                    curr = curr->right;
                }
            }
        }

        return minDif;
    }
};