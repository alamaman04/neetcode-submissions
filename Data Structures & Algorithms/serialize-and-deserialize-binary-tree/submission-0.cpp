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

class Codec {
public:

    // Encodes a tree to a single string.

    void preorder(TreeNode* root, string &s){
        if(root== nullptr) {
            s += "N,";
            return ;
        }
        s+= to_string(root->val) + "," ;
        preorder(root->left,s) ;
        preorder(root->right,s) ;
    }

    TreeNode* build(vector<string>&arr , int &idx){
        if(arr[idx]=="N" || idx >= arr.size()){
            idx++ ;
            return nullptr ;
        }

        TreeNode* root = new TreeNode(stoi(arr[idx])) ;
        idx++ ;
        root->left = build(arr,idx) ;
        root->right = build(arr,idx) ;
        return root ;
    }

    string serialize(TreeNode* root){ 
       string ans = "" ;
       preorder(root,ans) ;
       ans.pop_back() ;
       return ans ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>arr ; 
        // split the string 
        string cur = "" ;
        for(auto ch : data ){
            if(ch==','){
                arr.push_back(cur) ;
                cur = "" ;
            }else {
                cur+= ch ;
            }
        }
        arr.push_back(cur) ;

        int idx = 0 ;
        return build(arr,idx) ;

    }
};
