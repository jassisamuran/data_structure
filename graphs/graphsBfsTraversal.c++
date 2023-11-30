#include<iostream>
using namespace std;
#include<vector>
void addEdge(vector<int>graph[],int u,int v){
  graph[u].push_back(v);
  graph[v].push_back(u);
}
void traversal(int v,vector<int>graph[],vector<bool>&visited){
 cout<<v<<" ";
 for(auto i:graph[v]){
   if(!visited[i]){
     visited[i]=1;
     traversal(i,graph,visited);
   }
 }

}
int main(){
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    vector<bool>visited(5,false);
    int i=0;visited[i]=true;
    traversal(i,adj,visited);
}
