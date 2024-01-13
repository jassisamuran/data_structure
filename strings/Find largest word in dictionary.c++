class Solution {
  public:
    string ans="";
    void algo(string s,string n){
        int i=0; int j=0; 
        while(i<s.size() && j<n.size()){
            if(s[i]==n[j]){
                i++; j++;
            }else{
                i++;
            }
        }
        if(n.size()>ans.size() and j==n.size())ans=n;
    }
  
   string findLongestWord(string s, vector<string> d) {
        // code here
        sort(d.begin(),d.end());
        for(auto i:d){
            algo(s,i);
        }
        return ans;
    }
};
// time complexity o(s.size() *d.size())
// space complexity o(1)