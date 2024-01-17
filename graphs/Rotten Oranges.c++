class Solution 
{
    public:
    int m,n;
    int check(int i,int j){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
       queue<pair<int,int>>q;
       for(int i=0; i<grid.size(); i++){
           for(int j=0; j<grid[0].size(); j++){
               if(grid[i][j]==2){q.push({i,j});grid[i][j]=0;}
           }
       }
        int x[] = { -1, 0, 1, 0 };
        int y[] = { 0, 1, 0, -1 };
       int time=0;
       while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                auto front=q.front();
                q.pop();
                int first=front.first;
                int second=front.second;
                
                for(int i=0; i<4; i++){
                    if(check(first+x[i],second+y[i]) && grid[first+x[i]][second+y[i]]==1){
                        grid[first+x[i]][second+y[i]]=0;
                        q.push({first+x[i],second+y[i]});
                    }
                }
            }
            time++;
       }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1; 
                }
            }
        }

        return (time > 0) ? time - 1 : 0;
    }
};
// time complexity o(n*m)
// space complexity o(n*m)