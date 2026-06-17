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
    void dfs(TreeNode* node ,int &cnt,int k){
        if(node == nullptr) return ;
        dfs(node->left,cnt ,k) ;
        cnt++;
        if(cnt==k) ans = node->val ;
        dfs(node->right,cnt,k) ;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0 ;
         dfs(root ,cnt ,k) ;
         return ans ;
    }
};
