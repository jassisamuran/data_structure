#include<iostream>
using namespace std;
#include<vector>
bool iscycle(int src,vector<bool>&visited,vector<vector<int>>&g,int parent){
   visited[src]=1;
   for(auto i:g[src]){
     if(i!=parent){
       if(visited[i])return 1;
       if(!visited[i] &&iscycle(i,visited,g,src))return 1;
     }
   }
   return 0;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>g(n);
  for(int i=0; i<m; i++){
    int u,v;cin>>u>>v;
    g[u].push_back(v);
  }
  vector<bool>visited(n);
  for(int i=0; i<n; i++){
    if(!visited[i] && iscycle(i,visited,g,-1)){
       cout<<"cycle is present";break;
    }
  }

}
