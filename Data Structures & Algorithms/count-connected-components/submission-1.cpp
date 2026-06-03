class Solution {
public:
void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
    vis[i]=1;
    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
            dfs(adj[i][j],adj,vis);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
vector<vector<int>>adj(n);
int a=edges.size();
for(int i=0;i<a;i++){
    adj[edges[i][0]].push_back(edges[i][1]);  
     adj[edges[i][1]].push_back(edges[i][0]);
}
vector<int>vis(n,0);
int c=0;
for(int i=0;i<n;i++){
    if(!vis[i]){
        c++;
        dfs(i,adj,vis);
    }
}
return c;
    }
};
