class Solution {
public:
void fxn(vector<int>&temp,vector<int>& nums,set<int>&st,int n,  vector<vector<int>>&res){
    if(temp.size()==n){
        res.push_back(temp);
        return ;
    }
    for(int i=0;i<n;i++){
        if(!st.count(nums[i])){
        temp.push_back(nums[i]);
        st.insert(nums[i]);
        fxn(temp,nums,st,n,res);
        temp.pop_back();
        st.erase(nums[i]);
        }
    }
    return;
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        set<int>st;
        int n=nums.size();
        fxn(temp,nums,st,n,res);
        return res;
    }
};