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
    bool dfs(TreeNode* node , int l , int r){
        // base case 
        if(node->left == nullptr && node->right == nullptr){
           if(node->val >=l  && node->val <= r) return true ;
           else return false ;
        }
        
        bool left = node->left == nullptr || dfs(node->left,l,node->val-1) ;
        bool right = node->right == nullptr || dfs(node->right,node->val+1,r) ;
      
        bool good = node->val >= l  && node->val<= r;

        if(left && right && good) return true ;
        else return false ; 


    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-1000,1000) ;
    }
};
