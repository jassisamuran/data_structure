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
private:
TreeNode *traverse(TreeNode *root){
    while(root && root->left){
        root=root->left;
    }
    return root;
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            if(root->left==NULL){
                TreeNode *data=root->right;
                delete(root);
                return data;
            }else if(root->right==NULL){
                TreeNode *data=root->left;
                delete(root);
                return data;
            }
            TreeNode *next=traverse(root->right);
            root->val=next->val;
            root->right=deleteNode(root->right,next->val);
        }
        return root;
    }
};
// time complexity o(log n) if tree is skewed like linked list then o(n)
// space complexity o(1)