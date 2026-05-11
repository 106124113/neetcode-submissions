class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
      int i=0,j=0;
      vector<int>ans;
      unordered_map<int,int>mp;
      while(j<n){
           mp[nums[j]]++;
        if(j-i+1==k){
            int maxi=INT_MIN;
for(auto it:mp){
    maxi=max(maxi,it.first);
}
ans.push_back(maxi);
mp[nums[i]]--;
 if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
i++;
        }
         j++;
      }
      return ans;
    }
};
