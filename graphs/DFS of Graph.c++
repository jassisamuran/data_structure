class Solution {
  public:
    vector<int>ans;
    void dfs(int i,vector<int>&vis,vector<int>adj[]){
        ans.push_back(i);
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(j,vis,adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      vector<int>v(V,0);
       dfs(0,v,adj);
       return ans;
    }
};
// time complexity o(V+E) V is vertex and E is edges
// space complexity o(V) 