class Solution {
  public:
    int dfs(int source,int des,int n,vector<int>&dp,vector<int>&vis,vector<int>adj[]){
        if(dp[source]!=-1)return dp[source];
        if(source==des)return 1;
        vis[source]=1;
        int ans=0;
        for(int j:adj[source]){
            if(!vis[j]){
                ans+=dfs(j,des,n,dp,vis,adj);
            }
            
        }
        vis[source]=0;
        return dp[source]=ans;
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<int>vis(V,0);
        vector<int>dp(V,-1);
        return dfs(source,destination,V,dp,vis,adj);
    }
};
// time complexity O(V+E)
// space complexity O(V)