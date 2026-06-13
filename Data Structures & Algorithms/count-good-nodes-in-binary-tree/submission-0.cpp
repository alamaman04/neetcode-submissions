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
    void dfs (TreeNode* node ,int maxi, int &good ){
        if(node->val >= maxi) {
            good++ ;
            maxi = node->val ;
        }
        if(node->left) dfs(node->left, maxi , good) ;
        if(node->right) dfs(node->right, maxi, good) ;

    }
    int goodNodes(TreeNode* root) {
        int good = 0 ;
        dfs(root,-101,good) ;
        return good ;
    }
};
