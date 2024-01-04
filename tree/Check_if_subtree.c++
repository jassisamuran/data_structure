class Solution
{
  public:
    bool chk(Node *t,Node *s){
        if(!t and !s)return 1;
        if(!t || !s)return 0; 
        
        return (t->data == s->data) && chk(t->left, s->left) && chk(t->right, s->right);
   
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {   
        if(!T)return 0; 
        if(T->data ==S->data){
            if(chk(T,S)){
                return 1;
            }
        }
        
    return isSubTree(T->left,S)||isSubTree(T->right,S);
    }
};
// time complexity o(n*n) 
// space complexity o(n)