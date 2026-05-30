class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
      int n=grid.size(),m=grid[0].size();
      queue<pair<pair<int,int>,int>>q;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
               q.push({{i,j},0});
            }
        }
      }  
while(!q.empty()){
    int row=q.front().first.first;
    int col=q.front().first.second;
    int t=q.front().second;
    q.pop();
    if(col<m-1  && grid[row][col+1]>t+1){
grid[row][col+1]=t+1;
        q.push({{row,col+1},t+1});
    }
    if(row<n-1   && grid[row+1][col]>t+1){
       grid[row+1][col]=t+1;
        q.push({{row+1,col},t+1}); 
    }
    if(col>0  && grid[row][col-1]>t+1){
        grid[row][col-1]=t+1;
        q.push({{row,col-1},t+1});
    }
    if(row>0 && grid[row-1][col]>t+1){
        grid[row-1][col]=t+1;
        q.push({{row-1,col},t+1});
    }
}
    }
};
