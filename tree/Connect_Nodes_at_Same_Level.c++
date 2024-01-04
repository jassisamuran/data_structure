
class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
     queue<Node*>q;
     q.push(root);
     while(!q.empty()){
         int s=q.size();
         for(int i=0; i<s;i++){
             Node *nxt=q.front();q.pop();
             if(i+1<s)
             nxt->nextRight=q.front();
             else 
             nxt->nextRight=NULL;
             if(nxt->left)q.push(nxt->left);
             if(nxt->right)q.push(nxt->right);
             
         }
         
     }
    }    
      
};
