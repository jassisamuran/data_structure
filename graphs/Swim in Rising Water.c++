    class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
            vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
            int x[]={0,1,0,-1};
            int y[]={-1,0,1,0};
            pq.push({grid[0][0],{0,0}});
            vis[0][0]=1;
            int ans=0; 
            while(!pq.empty()){
                pair<int,pair<int,int>>p=pq.top();
                pq.pop();
                int f=p.second.first;
                int s=p.second.second;
                int value=p.first;
                ans=value;
                if(f==grid.size()-1 && s==grid[0].size()-1)return value;
                for(int i=0; i<4; i++){
                    int xi=f+x[i];int yi=s+y[i];
                    if(xi>=0 && yi>=0 && xi<grid.size() &&yi<grid[0].size() && vis[xi][yi]==0){
                        pq.push({max(value,grid[xi][yi]),{xi,yi}});
                        vis[xi][yi]=1;
                    }
                }
            }
            return ans; 
        }
    };
    time complexity o(nlog(n))
    space complexity o(n*n)