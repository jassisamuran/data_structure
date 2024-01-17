class Solution{
  public:
    int cut(int idx,int price[],int n,vector<vector<int>>&dp){
        if(idx==0){
            return n*price[0];
        }
        if (dp[idx][n] != -1)return dp[idx][n];
        int taken=0;
        int nottaken=cut(idx-1,price,n,dp);
        int len=idx+1;
        if(len<=n){
            taken=price[idx]+cut(idx,price,n-len,dp);
        }

        return dp[idx][n]=max(nottaken,taken);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return cut(n-1,price,n,dp);
     
    }
};
// time complexity o(n*n)
// space complexity o(n*n)