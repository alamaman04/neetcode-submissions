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
    int pre_idx ; // to track preorder index 
    unordered_map<int,int>index ;

    TreeNode* dfs(vector<int>&preorder,int l ,int r){
        if(l>r) return nullptr ;
        int root_val = preorder[pre_idx++] ;
        TreeNode* root = new TreeNode(root_val) ;
        int mid = index[root_val] ;
        TreeNode* left  = dfs(preorder , l , mid-1) ;
        TreeNode* right = dfs(preorder ,mid+1 ,r) ;
        root->left = left ;
        root->right = right ;
        return root ;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= inorder.size() ;
        for(int i=0 ;i<inorder.size() ;i++) index[inorder[i]] = i ;
        pre_idx = 0 ;
        return dfs(preorder,0,n-1) ;

    }
};
