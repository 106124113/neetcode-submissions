class Solution {
public:
vector<int> topo(int x,unordered_map<int,vector<int>>&adj, vector<int>&indegree){
queue<int>q;
vector<int>res;
int count=0;
for(int i=0;i<x;i++){
    if(indegree[i]==0){
        q.push(i);
        res.push_back(i);
        count++;
    }
}
while(!q.empty()){
    int a=q.front();
    q.pop();
    for(int &v:adj[a]){
        indegree[v]--;
        if(indegree[v]==0){
            count++;
            q.push(v);
            res.push_back(v);
        }
    }
}
if(count==x) return res;
return {};
}
    vector<int> findOrder(int x, vector<vector<int>>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(x,0);
        for(int i=0;i<n;i++){
            adj[nums[i][1]].push_back(nums[i][0]);
            indegree[nums[i][0]]++;
        }
        return topo(x,adj,indegree);
    }
};
