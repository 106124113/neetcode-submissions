class Solution {
public:
void dfs(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<bool>>&vis,int n,int m){
    if(i<0 || i>n-1 || j<0 || j>m-1) return;
    if(vis[i][j]) return;
    if(heights[i][j]<prev) return;
    vis[i][j]=true;
     dfs(heights, i+1, j, heights[i][j],vis, n, m);
           dfs(heights, i-1, j, heights[i][j],vis, n, m);
                dfs(heights, i, j+1, heights[i][j],vis, n, m);
                     dfs(heights, i, j-1, heights[i][j],vis, n, m);
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false)),atlantic(n,vector<bool>(m,false));
       for(int j=0;j<m;j++){
        dfs(heights,0,j,INT_MIN,pacific,n,m);
        dfs(heights,n-1,j,INT_MIN,atlantic,n,m);
       }
       for(int i=0;i<n;i++){
        dfs(heights,i,0,INT_MIN,pacific,n,m);
        dfs(heights,i,m-1,INT_MIN,atlantic,n,m);
       }
       vector<vector<int>>ans;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pacific[i][j] && atlantic[i][j]) {
                ans.push_back({i,j});
            }
        }
       }
       return ans;
    }
};
