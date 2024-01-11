class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int>l(n),r(n);
        l[0]=arr[0];
        
        for(int i=1; i<n;i++)l[i]=max(arr[i],l[i-1]);
        r[n-1]=arr[n-1];
        
        for(int i=n-2; i>=0; i--)r[i]=max(arr[i],r[i+1]);
        long long  ans=0; 
        
        for(int i=1; i<n-1; i++){
            long long cur=min(l[i-1],r[i+1]);
            if(cur>arr[i]){
                ans+=cur-arr[i];
            }
        }
        return ans;
    }
};
// time complexity o(n)
// space complexity o(n)