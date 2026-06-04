class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int a=points[0][0],b=points[0][1];
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int x=0;
        int ans=0;
        while(!pq.empty()){
         int t=pq.top().first;
         int idx=pq.top().second;
         pq.pop();
         if(vis[idx]){
            continue;
         }
         vis[idx]=1;
x++;
ans+=t;
         if(x==n) return ans;
         int mini=INT_MAX;
         int j;
for(int i=0;i<points.size();i++){
    if(!vis[i]){
        int dist=abs(points[idx][0]-points[i][0])+abs(points[idx][1]-points[i][1]);
        pq.push({dist,i});
    }
}
        }
        return 0;
    }
};
