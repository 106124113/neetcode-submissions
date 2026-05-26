class Solution {
public:
    void fxn(int i,int n,vector<int>& nums,int target,vector<vector<int>>& ans,vector<int>& temp)
    {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i == n) return;
        if(nums[i] <= target){
            temp.push_back(nums[i]);
            fxn(i, n, nums, target - nums[i], ans, temp);
            temp.pop_back();
        }
        fxn(i + 1, n, nums, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        fxn(0, nums.size(), nums, target, ans, temp);

        return ans;
    }
};
