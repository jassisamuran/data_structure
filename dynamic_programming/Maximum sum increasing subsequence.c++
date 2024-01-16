class Solution{
	public:
	int algo(int i,int parent,int n,int arr[],vector<vector<int>>&dp){
	    if(i>=n)return 0; 
	    
	    if(dp[i][parent+1]!=-1)return dp[i][parent+1];
	    
	    int taken=0;
	    if(parent==-1 || arr[i]>arr[parent]){
	        taken=arr[i]+algo(i+1,i,n,arr,dp);
	    }
	    int nottaken=algo(i+1,parent,n,arr,dp);
	    return dp[i][parent+1]=max(taken,nottaken);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return algo(0,-1,n,arr,dp);
	}  
};
// time complexity o(n*n)
// space complexity o(n*n)