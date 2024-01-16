class Solution{
public:
    int maximumPath(int N, vector<vector<int>> dp)
    {
        for(int i=1; i<N; i++){
            for(int j=0; j<N; j++){
                if(j>0 && j<N-1){
                    dp[i][j]+=max({dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]});
                }
                else if(j>0){
                    dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
                }else if(j<N-1){
                    dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
                }
            }
        }
        int ans=0;
        for(int i=0; i<N; i++){
            ans=max(ans,dp[N-1][i]);
        }
    return ans;
    }
};
// time complexity o(n*n)
// space complexity o(1)