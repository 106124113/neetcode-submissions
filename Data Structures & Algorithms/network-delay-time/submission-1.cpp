class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // int n=times.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,k});
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<times.size();i++){
        adj[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    vector<int>vis(n+1,0);
    int x=0;
    while(!pq.empty()){
        int t=pq.top().first;
        int node=pq.top().second;
        pq.pop();
if(!vis[node]){
    vis[node]=1;
    x++;
}
else continue;
if(x==n) return t;
for(int i=0;i<adj[node].size();i++){
    if(!vis[adj[node][i].first]){
        pq.push({t+adj[node][i].second,adj[node][i].first});
    }
}
    }
return -1;
    }
};
