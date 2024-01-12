class Solution
{
public:
    map<string,int>m;
    int check(string s,vector<int>&dp){
        if(s.size()==0)return 1; 
        int size=s.size();
        if(dp[s.size()]!=-1)return dp[s.size()];
        int d=0;
        for(int i=1 ; i<=s.size(); i++){
            if(m[s.substr(0,i)] && check(s.substr(i,size-i),dp))d= 1; 
            
        }
        
        return dp[s.size()]=d; 
    }
 
    int wordBreak(string A, vector<string> &B) {
        for(int i=0; i<B.size(); i++)m[B[i]]++;
        vector<int>dp(A.size()+1,-1);
        return check(A,dp);
    }
};
// time complexity o(n*n)
// space complexity o(n)