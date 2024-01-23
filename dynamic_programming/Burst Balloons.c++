class Solution {
public:
    int check(int idx,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(idx>n)return 0;
        if(dp[idx][n]!=-1)return dp[idx][n];
        int val=INT_MIN;
        for(int i=idx; i<=n; i++){
            int data=nums[idx-1]*nums[i]*nums[n+1]+check(idx,i-1,nums,dp)+check(i+1,n,nums,dp);
            val=max(val,data);
        }
        return dp[idx][n]=val;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
      vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
      nums.insert(nums.begin(),1);
      nums.push_back(1);
      return check(1,n,nums,dp);  
    }
};
// time complexity o(n*n*n)
// space complexity o(n*n)