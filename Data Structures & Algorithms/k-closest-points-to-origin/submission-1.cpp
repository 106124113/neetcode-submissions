class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans(k,vector<int>(2));
        int n=points.size();
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            double d=sqrt(x*x+y*y);
            pq.push({d,i});
            if(pq.size()>k) pq.pop();
        }
        int x=0;
        while(!pq.empty()){
            int i=pq.top().second;
            pq.pop();
            ans[x][0]=points[i][0];
            ans[x][1]=points[i][1];
            x++;
        }
        return ans;
    }
};
