// Given a binary tree, find the maximum path sum.

// The path may start and end at any node in the tree.

// For example:
// Given the below binary tree,

//        1
//       / \
//      2   3
// Return 6.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxLen = INT_MIN;
        helper(root, maxLen);
        return maxLen;
    }
    
    int helper(TreeNode *root, int &maxLen) {
       if(!root) return 0;
       int leftMaxPath, rightMaxPath;
       leftMaxPath = helper(root->left, maxLen);
       rightMaxPath = helper(root->right, maxLen);
       int arch = leftMaxPath + root->val + rightMaxPath;
       int maxPath = max(root->val, max(leftMaxPath, rightMaxPath)+root->val);
       maxLen = max(maxLen, max(arch, maxPath));
       return maxPath;
    }
};
