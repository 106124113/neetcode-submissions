class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
vec[i].first=position[i];
vec[i].second=speed[i];
        }
       sort(vec.begin(),vec.end());
       stack<double>st;
       for(int i=n-1;i>=0;i--){
        double t=(target-vec[i].first)/(double)vec[i].second;
        if(st.empty() || (!st.empty() && t>st.top())) st.push(t);
       }
return st.size();
    }
};