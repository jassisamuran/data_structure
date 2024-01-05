class Solution{
    public:
    long long algo(int i,int j,int n,int arr[],vector<vector<int>>&dp){
        if ((i > j) || (i >= n) || (j < 0)) 
            return 0; 
       if(dp[i][j]!=-1)return dp[i][j];
       long long first=arr[i]+min(algo(i+2,j,n,arr,dp),algo(i+1,j-1,n,arr,dp));
       long long second=arr[j]+min(algo(i+1,j-1,n,arr,dp),algo(i,j-2,n,arr,dp));
       return dp[i][j]=max(first,second);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return algo(0,n-1,n,arr,dp);
    }
};