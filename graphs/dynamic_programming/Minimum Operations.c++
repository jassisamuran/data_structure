class Solution
{
  public:
    int minOperation(int n)
    {
        int cnt=0;
        while(n>0){
          if(n&1)n--;
          else n=n/2;
          cnt++;
        }
        return cnt;
    }
};
// time complexity o(log(n))
// space complexity o(1)