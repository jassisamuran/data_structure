class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {   vector<int>lps(pat.size(),0);
            int k=0;
            for(int i=1; i<pat.size(); i++){
                int j=lps[i-1];
                while(j>0 and pat[j]!=pat[i]){
                    j=lps[j-1];
                }
                if(pat[j]==pat[i])j++;
                lps[i]=j;
            }
            
            vector<int>ans;
            int i=0,j=0;
            int m=pat.size();
            while(i<txt.size()){
                if(pat[j]==txt[i]){
                    i++; j++;
                }
                if(j==m){
                    ans.push_back(i-(m-1));
                    j=lps[j-1];
                }else if(pat[j]!=txt[i]){
                    if(j==0)i++;
                    j=lps[j-1];
                }
            }
            return ans;
        }
     
};
// time complexity(n+m)
