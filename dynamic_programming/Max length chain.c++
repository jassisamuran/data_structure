class Solution{
public:
    bool static comp(val fst, val sec){
        return fst.second<sec.second;
    }
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        sort(p,p+n,comp);
        int f=p[0].second;int cnt=0; 
        for(int i=1;i<n; i++){
            if(p[i].first>f){
                f=p[i].second;
                cnt++;
            }
        }
    
    return cnt+1;
    }
};
// time complexity o(n*log(n))
// space complexity o(1)