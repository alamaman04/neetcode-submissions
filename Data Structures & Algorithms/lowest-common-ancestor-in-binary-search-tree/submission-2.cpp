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

    // TreeNode* lca(TreeNode* root , TreeNode * p ,TreeNode *q){
    //     if(root == nullptr) return nullptr ;
    //     if(root == p || root == q) return root ;

    //     TreeNode * left = lca(root->left,p,q) ;
    //     TreeNode* right = lca(root->right,p,q) ;
    //     if(left== nullptr) return right ;
    //     else if(right == nullptr) return left ;
    //     else return root ;

    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //return lca(root,p,q) ;
        // this is BST 
        // left<root<right ;
        if(p->val > q->val) swap(p,q);
        while(root != nullptr){
            if(p->val > root->val && q->val > root->val) {
                root = root->right ;
            }
            else if(p->val <root->val && q->val<root->val) {
                root = root->left ;
            }
            else return root ;
        }
        return nullptr ;
    }
};
