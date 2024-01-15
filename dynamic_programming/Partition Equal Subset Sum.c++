class Solution{
public:
    bool divide(int idx,int n,long long sum,int arr[],vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(sum<0)return 0;
        if(idx>=n)return 0; 
        if(dp[sum][idx]!=-1)return dp[sum][idx];
        int taken=divide(idx+1,n,sum-arr[idx],arr,dp);
        int nottaken=divide(idx+1,n,sum,arr,dp);
        return dp[sum][idx]=taken||nottaken;
    }
    int equalPartition(int N, int arr[])
    {
        long long sum =0; 
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        vector<vector<int>>dp(sum/2+1,vector<int>(N,-1));
        return divide(0,N,sum/2,arr,dp);
    }
};
// time complexity o(n*n)
// space complexity o(n*n)