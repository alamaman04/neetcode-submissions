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
    int ans ;
// i have to find max path sm starting at each index ;
    int dfs(TreeNode* node){
        // base case 
        if(node == nullptr) return 0 ;
        int left = dfs(node->left) ;
        int right = dfs(node->right) ;

        ans = max(ans,left+right+node->val) ;
        int dp = max(node->val ,node->val+ max(left,right)) ;
        ans = max(ans, dp) ;
        return dp ;

    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN ;
        dfs(root) ;
        return ans ;
    }
};
