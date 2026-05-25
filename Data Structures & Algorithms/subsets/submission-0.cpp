class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>>ans(pow(2,n));
         int k=0;
         ans[k]={};
         k++;
         for(int i=0;i<n;i++){
            int sz=k;
            for(int j=0;j<sz;j++){
                for(int x=0;x<ans[j].size();x++){
                    ans[k].push_back(ans[j][x]);
                }
                ans[k].push_back(nums[i]);
                k++;
            }
         }
         return ans;
    }
};