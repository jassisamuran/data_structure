class Solution{
  public:
   int check(int i,int j,string s1,string s2,string s3,vector<vector<int>>&dp){
        if(i+j==s3.size())return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0,b=0; 
        if(s1[i]==s3[i+j]){
            a=check(i+1,j,s1,s2,s3,dp);
        }
         if(s2[j]==s3[i+j]){
            b=check(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j]=a||b;
    }
    /*You are required to complete this method */
    bool isInterleave(string s1, string s2, string s3) 
    {
        //Your code here
        if(s1.size()+s2.size()!=s3.size())return 0;
        vector<vector<int>>dp(s3.size(),vector<int>(s3.size(),-1));
        return check(0,0,s1,s2,s3,dp);
    }
    

};
// time complexity o(n*n)
// space complexity o(n*m)