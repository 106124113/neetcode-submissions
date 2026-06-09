class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
       priority_queue<  pair<int,pair<int,int>>,vector<  pair<int,pair<int,int>>>,greater<  pair<int,pair<int,int>>>>pq;
       pq.push({grid[0][0],{0,0}});
       vector<vector<int>>vis(n,vector<int>(n,0));
       int maxi=INT_MIN;
       while(!pq.empty()){
        int t=pq.top().first;
        int row=pq.top().second.first;
         int col=pq.top().second.second;
         vis[row][col]=1;
         pq.pop();
         maxi=max(maxi,t);
         if(row==n-1 && col==n-1) return maxi;
         if(row>0 && !vis[row-1][col]){
            pq.push({grid[row-1][col],{row-1,col}});
         }
         if(row<n-1 && !vis[row+1][col]){
            pq.push({grid[row+1][col],{row+1,col}});
         }
         if(col>0 && !vis[row][col-1]){
            pq.push({grid[row][col-1],{row,col-1}});
         }
         if(col<n-1 && !vis[row][col+1]){
            pq.push({grid[row][col+1],{row,col+1}});
         }
       }
       return maxi;
    }
};