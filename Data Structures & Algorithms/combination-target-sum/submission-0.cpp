class Solution {
public:
    void fxn(int i,
             int n,
             vector<int>& nums,
             int target,
             vector<vector<int>>& ans,
             vector<int>& temp)
    {
        // base case
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        // out of bounds
        if(i == n) return;

        // take
        if(nums[i] <= target){
            temp.push_back(nums[i]);

            fxn(i, n, nums, target - nums[i], ans, temp);

            temp.pop_back(); // backtrack
        }
        // not take
        fxn(i + 1, n, nums, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        fxn(0, nums.size(), nums, target, ans, temp);

        return ans;
    }
};
