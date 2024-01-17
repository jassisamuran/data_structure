class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int check(int i,vector<int>&vis,vector<int>&stack,vector<int>adj[]){
        vis[i]=1;
        stack[i]=1;
        for(auto j:adj[i]){
            if(!vis[j] && check(j,vis,stack,adj)){
             return 1;   
            }else if(stack[j])return 1;
        }
        stack[i]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);vector<int>stack(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i] && check(i,vis,stack,adj))return 1; 
        }
        return false;
    }
};
// time complexity o(V+E) V is vertex and E is edges
// space complexity o(V)