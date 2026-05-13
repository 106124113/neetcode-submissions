class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
      stack<pair<int,int>>st;
      int n=nums.size();
      vector<int>ans(n,0);
      st.push({nums[n-1],n-1});
for(int i=n-2;i>=0;i--){
    while(!st.empty() && nums[i]>=st.top().first){
        st.pop();
    }
    if(!st.empty())ans[i]=st.top().second-i;
    st.push({nums[i],i});
}
return ans;
    }
};
