class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int>adj[k];
        for(int i=0; i<N-1; i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int j =0;j<len;  j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        int indegree[k]={0};
        for(int i=0; i<k; i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q; vector<int>ans;
        for(auto i=0; i<k; i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto j:adj[node]){
                indegree[j]--;
                if(indegree[j]==0)q.push(j);
            }
        }
        string ret=""; 
        for(auto i:ans){
            ret=ret+char(i+'a');
        }
        return ret;
    }
};
// time complexity o(n*s+ K) n is length of dict, s is lenght of dict[i]
// space complexity o(k)