#include<isotream>
using namespace std;
#include<vector>
void makeSet(vector<int>&parent,vector<int>&rank,int n){
 for(int i=0; i<n; i++){
   parent[i]=i;
   rank[i]=0;
 }
}
int findparent(vector<int>&parent,int node){
  if(parent[node]==node)return node;
  return parent[node]=findparent(parent,parent[node]);
}
void unionSet(int u,int v,vector<int>&parent){
  u=findparent(parent,u);
  v=findparent(parent,v);
  if(rank[u]<rank[v]){
	parent[u]=v;
  }else if(rank[v]<rank[u]){
    parent[u]=v
  }else{
     parent[v]=u;
     rank[u]++;
  }

}
int main(){
 int n=1000;
 vector<int>parent(n);
 vector<int>rank(n);
 makeSet(parent,rank,n);
}
