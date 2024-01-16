class Solution{
	public:
	int square(int n,vector<int>&dp){
	    if(n<=0)return 0; 
	    if(dp[n]!=-1)return dp[n];
	    int no=0;int ans=INT_MAX;
	    for(int i=1; i<=sqrt(n);i++){
	         no=1+square(n-i*i,dp);
	         ans=min(no,ans);
	    }
	  
	    return dp[n]=ans;
	}
	int MinSquares(int n)
	{
	    vector<int>dp(n+1,-1);
	    return square(n,dp);
	}
};

space complexity o(n)