class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
           int n=heights.size();
           stack<pair<int,int>>st;
           int maxi=INT_MIN;
      for(int i=0;i<n;i++){
while(!st.empty() && heights[i]<st.top().first){
    int a=st.top().first;
    st.pop();
    int prev=-1;
    if(!st.empty()) prev=st.top().second;
maxi=max(maxi,(i-prev-1)*a);
}
st.push({heights[i],i});
      }
      while(!st.empty()){
        int a=st.top().first;
        st.pop();
        int prev=-1;
        if(!st.empty()) prev=st.top().second;
        maxi=max(maxi,(n-prev-1)*a);
      }
      return maxi;
    }
};
