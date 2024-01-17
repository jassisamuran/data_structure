class Solution{
public:
    int mcm(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int steps=INT_MAX;
        for(int k=i; k<j;  k++){
            int d=arr[i-1]*arr[k]*arr[j]+mcm(i,k,arr,dp)+mcm(k+1,j,arr,dp);
            steps=min(steps,d);
        }
        return dp[i][j]=steps;
    }
    int matrixMultiplication(int N, int arr[])
    {
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return mcm(1,N-1,arr,dp);
    }
};