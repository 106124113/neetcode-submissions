class Solution {
public:
bool dfs(int i,int parent,int x, vector<vector<int>>& adj,vector<int>&vis){
    vis[i]=1;
    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
if(!dfs(adj[i][j],i,x,adj,vis)) return false;
        } 
        else if(adj[i][j]!=parent) return false;
    }
    return true;
}

    bool validTree(int x, vector<vector<int>>& nums) {
vector<vector<int>> adj(x);
        int n=nums.size();
        for(int i=0;i<n;i++){
           adj[nums[i][0]].push_back(nums[i][1]);
               adj[nums[i][1]].push_back(nums[i][0]);
        }
        int ans;
        vector<int>vis(x,0);
                ans=dfs(0,-1,x,adj,vis);
           for(int i=0;i<x;i++){
            if(!vis[i]) return false;
           }
            return ans;
    }
};