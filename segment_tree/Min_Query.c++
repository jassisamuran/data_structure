class Solution {
  public:
  void build(int v[],int sgt[],int start,int end,int treeNode){
      if(start==end){
          sgt[treeNode]=v[start];
          return;
      }
      int mid=(start+end)/2;
      build(v,sgt,start,mid,2*treeNode);
      build(v,sgt,mid+1,end,2*treeNode+1);
      sgt[treeNode]=sgt[2*treeNode]&sgt[2*treeNode+1];
  }
  

int query(int sgt[],int start,int end,int treeNode,int left,int right){
    if(start>right || end<left){
        return (1<<31)-1;
    }
    if(start>=left && end<=right){
        return sgt[treeNode];
    }
    int mid=(start + end)/2;
    int q1=query(sgt, start, mid,2* treeNode, left, right);
    int q2=query(sgt,mid+1,end,2*treeNode+1,left,right);
    return q1&q2;
    
}


    vector<int> minQuery(int N, int Q, vector<int> &A, vector<vector<int>> &Queries) {
         int sgt[N*4];
        int v[N];
        for(int i = 0; i < N; i++){
             v[i] = A[i];
        }
        build(v,sgt,0,N-1,1);
        
        vector<int> ans;
        for(auto a : Queries){
          int aa = query(sgt,0,N-1,1,a[0]-1,a[1]-1);    
          int b = query(sgt,0,N-1,1,a[2]-1,a[3]-1);    
          ans.push_back(aa|b);
        }
        
        
        return ans;
    }
};
// time complexity o(nlog(n))
// space complexity o(nlog(n))