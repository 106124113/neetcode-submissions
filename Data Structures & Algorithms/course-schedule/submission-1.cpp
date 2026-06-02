class Solution {
public:
bool dfs(int i,int x, vector<vector<int>>& adj,vector<int>&vis,vector<int>&pathvis){
    vis[i]=1;
    pathvis[i]=1;
    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
if(!dfs(adj[i][j],x,adj,vis,pathvis)) return false;
        } 
        else if(pathvis[adj[i][j]]) return false;
    }
    pathvis[i]=0;
    return true;
}
    bool canFinish(int x, vector<vector<int>>& nums) {
        vector<vector<int>> adj(x);
        int n=nums.size();
        for(int i=0;i<n;i++){
           adj[nums[i][0]].push_back(nums[i][1]);
        }
        vector<int>vis(x,0),pathvis(x,0);
        for(int i=0;i<x;i++){
            bool ans=true;
            if(!vis[i]) {
                ans=dfs(i,x,adj,vis,pathvis);
            }
       if(ans==false) return false;
        }
        return true;
    }
};
