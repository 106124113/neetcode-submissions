class Solution {
public:
int find(int x,vector<int>&parent){
    if(x==parent[x]) return parent[x];
    return parent[x]=find(parent[parent[x]],parent);
}
vector<int> dsu(int a,int b,vector<int>&parent,vector<int>&rank){
    int pa=find(a,parent);
    int pb=find(b,parent);
    cout<<pa<<" "<<pb<<endl;
    if(pa==pb){
        return {a,b};
    }
    if(rank[pa]>=rank[pb]){
parent[pb]=pa;
rank[pa]++;
    }
    else if(rank[pa]<rank[pb]){
parent[pa]=pb;
rank[pb]++;
    }
    return {};
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
 vector<int>parent(n+1,0);
 for(int i=1;i<=n;i++)parent[i]=i;
 vector<int>rank(n+1,0);
 for(int i=0;i<n;i++){
    vector<int>ans;
    ans=dsu(edges[i][0],edges[i][1],parent,rank);
   if(ans.size()!=0) return ans; 
 }
 return {};
    }
};
