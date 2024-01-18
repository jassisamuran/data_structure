class Solution
{
    public:
    int drop_egg(int n,int k,vector<vector<int>>&dp){
        if(dp[n][k]!=-1)return dp[n][k];
        if(k==0 ||k==1)return k; 
        if(n==1)return k ;
        
        int mini=INT_MAX,res;
        for(int i=1; i<=k; i++){
            res=1+max(drop_egg(n-1,i-1,dp),drop_egg(n,k-i,dp));
            mini=min(res,mini);
        }
        return dp[n][k]=mini;
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {

        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return drop_egg(n,k,dp);
    }
};
// time complexity o(n*k*k)
// space complexity o(n*k)