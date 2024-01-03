
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
  int height(Node *root){
      if(!root)return 0; 
      int l=height(root->left);
      int r=height(root->right);
      return max(l,r)+1;
  }
  
    // Function to return the diameter of a Binary Tree.
    int diametermain(Node* root) {
        if(!root)return 0; 
        int l=height(root->left);
        int r=height(root->right);
        int cur=l+r+1;
        int diameterl=diametermain(root->left);
        int diameterr=diametermain(root->right);
        return max({cur,diameterl,diameterr});
        
    }
    // o(n*n) time complexity
    int diameter2(Node *root,int *height){
        if(root==NULL){
            *height=0;
            return 0; 
        }
        int lh=0,rh=0;
        int ldiameter=diameter2(root->left,&lh);
        int rdiameter=diameter2(root->right,&rh);
        int curdiameter=lh+rh+1;
        *height=max(lh,rh)+1;
        
        return max({ldiameter,rdiameter,curdiameter});
        
    }
    // o(n) solution
    
    int diameter(Node *root){
        int h=0;
        return diameter2(root,&h);
    }
};