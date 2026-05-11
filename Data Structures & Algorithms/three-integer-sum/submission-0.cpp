class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                     s.insert({nums[i],nums[j],nums[k]});
                     j++;
                     k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else j++;
            }
        }
        vector<vector<int>>ans;
        int i=0;
        for(auto it:s){
            ans.push_back({});
            vector<int>vec=it;
           ans[i].push_back(vec[0]);
            ans[i].push_back(vec[1]);
           ans[i].push_back(vec[2]);
           i++;
        }
        return ans;
    }
};
