class Solution
{
    public:
    long long mod=1e9+7;
    long long check(int n,vector<long long>&dp){
        if(n==1 || n==0){return 1;}
        if(n<0 )return 0; 
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(check(n-1,dp)%mod+check(n-2,dp)%mod+check(n-3,dp)%mod)%mod;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<long long>dp(n+1,-1);
        return check(n,dp);
    }
};
// time complexity o(n)
// space complexity o(n)