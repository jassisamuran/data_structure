class Solution{
public:
    vector<int> minPartition(int N)
    {   vector<int>ans;
        // code here
        int arr[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } ;
        for(int i=9;i>=0; i--){
            if(N>=arr[i]){
                int no=N/arr[i];
                for(int j=0; j<no; j++)ans.push_back(arr[i]);
                N=N%arr[i];
            }
        }
        return ans;
    }
};
// time complexity o(n)
// space complexity o(n)