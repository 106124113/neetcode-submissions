class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
  int n=nums.size();
vector<int>pref(n),suff(n);
pref[0]=nums[0];
suff[n-1]=nums[n-1];
for(int i=0;i<n;i++){
    if(i>0) pref[i]=pref[i-1]*nums[i];
    if(i<n-1) suff[n-i-2]=nums[n-i-2]*suff[n-i-1];
}
vector<int>ans(n);
ans[0]=suff[1];
ans[n-1]=pref[n-2];
for(int i=1;i<n-1;i++){
    ans[i]=pref[i-1]*suff[i+1];
}
return ans;
    }
};
