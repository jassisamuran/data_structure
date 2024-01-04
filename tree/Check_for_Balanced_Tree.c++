
class Solution{
    public:
    int ch=0;
    bool algo(Node *root,int *height){
        if(root==NULL)return 1;
        int lh=0,rh=0;
        if(algo(root->left,&lh)==false){
           return  false;
        }
        if(algo(root->right,&rh)==false){
          return 0;  
        }
        *height=max(lh,rh)+1;
        if(abs(lh-rh)<=1)return 1;
        return 0;
        
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {   
        int h=0;
        return algo(root,&h);
        
    }
};