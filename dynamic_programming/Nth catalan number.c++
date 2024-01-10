class Solution
{
    public:
    //Function to find the nth catalan number.
    int mod=1e9+7;
    int findCatalan(int n) 
    {
        long long arr[n + 1];
        arr[0]=arr[1]=1;
        for(int i=2;i<=n; i++){
            arr[i]=0;
            for(int j=0; j<i; j++){
                arr[i] = (arr[i] + (arr[j] * arr[i - j - 1]) % mod) % mod;
            }
        }
        return arr[n];
    }
};
// time complexity o(n*n);
// space complexity o(n)