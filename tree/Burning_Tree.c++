class Solution {
  public:
  Node *parent(Node *root,unordered_map<Node*,Node*>&m,int target){
      queue<Node*>q;
      q.push(root);
      Node *re;
      while(!q.empty()){
          Node *cur=q.front();
          q.pop();
          if(cur->data==target)re=cur;
          if(cur->left){
            m[cur->left]=cur;
            q.push(cur->left);    
          }
          if(cur->right){
              m[cur->right]=cur;
              q.push(cur->right);
          }
      }
      return re;
  }
    int finddistance(Node *cur,unordered_map<Node*,Node*>&m){
        unordered_map<Node*,int>vis;
        queue<Node*>q;
        int time=0;
        q.push(cur);
        vis[cur]=1;
        while(!q.empty()){
            int flag=0;
            int s=q.size();
            for(int i=0; i<s; i++){
                Node *ncur=q.front();q.pop();
                if(ncur->left &&!vis[ncur->left]){
                    q.push(ncur->left);
                    vis[ncur->left]=1;
                    flag=1;
                }
                if(ncur->right && !vis[ncur->right]){
                    q.push(ncur->right);
                    vis[ncur->right]=1;
                    flag=1;
                }
                if(m[ncur] && !vis[m[ncur]]){
                    q.push(m[ncur]);
                    vis[m[ncur]]=1;
                    flag=1;
                }
            }
            if(flag)time++;
        }
        return time;
    }
    // time complexity o(n)
    // space complexity o(n)
    int minTime(Node* root, int target) 
    {
       unordered_map<Node*,Node*>m; 
       Node *cur=parent(root,m,target);
       return finddistance(cur,m);
    }
};