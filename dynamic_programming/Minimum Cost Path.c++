class Solution
{
    public:int n,m;
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int range(int i,int j){
	    return (i>=0 && j>=0 and i<n and j<m);
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {   n=grid.size();m=grid[0].size();
        set<pair<int,pair<int,int>>>s;
        s.insert({grid[0][0],{0,0}});
       
        int dis[n][m];
 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dis[i][j] = INT_MAX;
        
        dis[0][0]=grid[0][0];
        int x[]={0,1,-1,0};
        int y[]={1,0,0,-1};
        while(!s.empty()){
            pair<int,pair<int,int>>p=*s.begin();
            s.erase(s.begin());
 
            int xi=p.second.first;
            int yi=p.second.second;
            for(int i=0;i<4; i++){
                int dx=xi+x[i],dy=yi+y[i];
                if(!range(dx,dy))continue;
                
                if(dis[dx][dy]>dis[xi][yi]+grid[dx][dy]){
                    if(dis[dy][dy]!=INT_MAX){
                        s.erase({dis[dx][dy],{dx,dy}});
                    }
                        
                    dis[dx][dy]=dis[xi][yi]+grid[dx][dy];
                    s.insert({dis[dx][dy],{dx,dy}});
                    
                }
            }
        }
        return dis[n-1][m-1];
    }
};
// time complexity o(n^2*log(n))
// space complexity o(n*n)