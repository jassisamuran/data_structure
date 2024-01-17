class Solution {
  public:
    long long chk(int m,int n,int x,vector<vector<long long>>&dp){
        if(x==0 and n==0)return 1;
        if(n<=0 || x<=0)return 0; 
        if(dp[x][n]!=-1)return dp[x][n];
        long long ans=0;
        for(int i=1; i<=m; i++){
            ans+=chk(m,n-1,x-i,dp);
        }
        return dp[x][n]=ans;
        
    }
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>>dp(X+1,vector<long long>(N+1,-1));
        return chk(M,N,X,dp);
        
        
    }
};
// Time complexity o(M*N*X)
// Space complexity o(X*N);