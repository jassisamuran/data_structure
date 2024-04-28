class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static cmp(vector<int>&f,vector<int>&s){
        if(f[1]<s[1])return 1; 
        else if(f[1]>s[1])return 0; 
        else if(f[2]<s[2])return 1;
        return 0; 
        
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>>v(n);
        for(int i=0; i<n; i++){
            v[i]={start[i],end[i],i+1};
        }
        sort(v.begin(),v.end(),cmp);
        int cont=v[0][1];int ans=1; 
        for(int i=1; i<n; i++){
            if(v[i][0]>cont){
                ans++;
                cont=v[i][1];
            }
        }
    
        return ans; 
    }
};

// time complexity o(nlog(n))
// space complexity o(n)