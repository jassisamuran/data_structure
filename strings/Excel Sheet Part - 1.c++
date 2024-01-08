class Solution{
    public:
    string ExcelColumn(int N)
    {
        // Your code goes here
        string ans="";
        while(N>0){
            N--;
            int d=N%26;
            ans=(char)(d+'A')+ans;
            N=N/26;
            
        }
        return ans;
    }
};
//  time complexity log(n)