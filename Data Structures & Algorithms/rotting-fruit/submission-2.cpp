class Solution {
public:
    int orangesRotting(vector<vector<int>>&grid) {
          int n=grid.size(),m=grid[0].size();
      queue<pair<pair<int,int>,int>>q;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
               q.push({{i,j},0});
            }
        }
      }
      int maxi=0;
        while(!q.empty()){
    int row=q.front().first.first;
    int col=q.front().first.second;
    int t=q.front().second;
    q.pop();
    maxi=max(maxi,t);
    if(col<m-1  && grid[row][col+1]==1){
grid[row][col+1]=2;
        q.push({{row,col+1},t+1});
    }
    if(row<n-1   && grid[row+1][col]==1){
       grid[row+1][col]=2;
        q.push({{row+1,col},t+1}); 
    }
    if(col>0  && grid[row][col-1]==1){
        grid[row][col-1]=2;
        q.push({{row,col-1},t+1});
    }
    if(row>0 && grid[row-1][col]==1){
        grid[row-1][col]=2;
        q.push({{row-1,col},t+1});
    }
}
  for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
              return -1;
            }
        }
      }
return maxi;
    }
};
