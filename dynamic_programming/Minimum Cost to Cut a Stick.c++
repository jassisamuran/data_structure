class Solution {
public:
int algo(int idx,int n,vector<int>&cuts,vector<vector<int>>&dp){
    if(idx>n)return 0; 
    if(dp[idx][n]!=-1)return dp[idx][n];
    int mini=INT_MAX;
    for(int i=idx; i<=n;i++){
        int data=cuts[n+1]-cuts[idx-1]+algo(idx,i-1,cuts,dp)+algo(i+1,n,cuts,dp);
        mini=min(data,mini);
    }
    return dp[idx][n]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int s=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>>dp(s+1,vector<int>(s+1,-1));
        return algo(1,s,cuts,dp);

    }
};
// time complexity o(n*n*n)
// space complexity o(n*n)