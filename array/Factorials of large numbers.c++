class Solution {
public:
    void multiply(vector<int>&res,int digit){
        int carry=0;
        for(int i=0; i<res.size(); i++){
            int next_digit=res[i]*digit+carry;
            res[i]=next_digit%10;
            carry=next_digit/10;
        }
        while(carry){
            res.push_back(carry%10);
            carry=carry/10;
        }
    }
    vector<int> factorial(int N){
        vector<int>ans;
        ans.push_back(1);
        for(int i=2; i<=N; i++){
            multiply(ans,i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// time complexity o(n*n)
// space complexity o(n)