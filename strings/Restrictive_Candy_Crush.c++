class Solution{
    public:
    string chk(int k,string s){
        stack<pair<char,int>>st;
        for(int i=0; i<s.size();i++){
            if(st.size()==0){
                st.push({s[i],1});
            }else{
               if (s[i] == (st.top()).first) {
                    pair<char, int> P = st.top();
                    st.pop();
                    P.second++;
                    if (P.second == k)
                        continue;
                    else
                        st.push(P);
                }else{
                    st.push({s[i],1});
                }
            }
        }
        string ans="";
        while(!st.empty()){
            pair<char,int>p=st.top();
            st.pop();
            while(p.second--){
                ans+=p.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string Reduced_String(int k,string s){
        if(k==1)return "";
        return chk(k,s);
    }


};