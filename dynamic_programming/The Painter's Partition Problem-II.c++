class Solution
{
  public:
    int checkData(int  arr[],int n,long long  limit){
        long long  sum=0;int painters=1;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum>limit){
                sum=arr[i];
                painters++;
            }
        }
        return painters;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sum=0;int mx=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            mx=max(arr[i],mx);
        }
        long long low=mx,high=sum;
        while(low<high){
            long long mid = low + (high - low) / 2;
            long long  value=checkData(arr,n,mid);
            if(value<=k){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
//  time complexity o(n * log m  ) where m is sum of all array
//  space complexity o(1)