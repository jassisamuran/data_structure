class Solution {
    int dp[501][201][2];
  public:
    int chk(int i,int buysell,int k,int n,int a[]){
        if(i>=n || k<0)return 0;
        int buy=0,sell=0;
        if(dp[i][k][buysell]!=-1)return dp[i][k][buysell];
        if(buysell==0){
            buy=max(-a[i]+chk(i+1,1,k-1,n,a),chk(i+1,0,k,n,a));
        }else{
            sell=max(a[i]+chk(i+1,0,k,n,a),chk(i+1,1,k,n,a));
        }
        return dp[i][k][buysell]=max(buy,sell);
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        for(int i=0; i<=N; i++){
            for(int j=0;j<=K; j++){
                dp[i][j][1] = -1;
                dp[i][j][0] = -1;
            }
        }
        return chk(0,0,K,N,A);
    }
};
// time complexity o(N*K)