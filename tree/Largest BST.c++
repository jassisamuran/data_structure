class Solution{
    public:
    struct Info{
        int sz;
        int max;
        int min;
        int ans;
        bool isBst;
    };
    Info Bst(Node* root){
        if(root == NULL){
            return {0, INT_MIN, INT_MAX, 0, 1};
        }
        if(root->left == NULL and root->right==NULL){
            return {1, root->data, root->data, 1, true};
        }
        Info l = Bst ( root -> left);
        Info r = Bst ( root -> right);
        
        Info ret;
        ret.sz = l.sz + r.sz + 1;
         
        if(l.isBst &&  r.isBst && l.max < root->data && r.min > root->data){
            ret.min = min(l.min, root->data);
            ret.max = max(r.max,root->data);
            
            ret.ans = l.ans + r.ans + 1;
            ret.isBst=true;
            
            return ret;
        }
        
        ret.ans = max(l.ans, r.ans);
        ret.isBst = false;
        return ret;
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        	return Bst(root).ans;
    }
};
// time complexity o(n)
// space complexity o(1)