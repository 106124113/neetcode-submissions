class Solution {
public:
// void fxn(int i,int n,vector<int>&temp,set<vector<int>>&st,vector<vector<int>>&ans,vector<int>& nums){
//     for(int i=0;i<n;i++){
//    for(int j=0;j<ans.size;j++){
//    temp=ans[j];
//    temp.push_back(nums[i]);
// st.insert(temp);
// if(!st.count(temp)){
//     ans.push_back(temp);
// }
//    }
//     }
// }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
         vector<vector<int>>ans(1);
         set<vector<int>>st;
vector<int>temp;
int n=nums.size();
ans[0]={};
 for(int i=0;i<n;i++){
    int k=ans.size();
   for(int j=0;j<k;j++){
   temp=ans[j];
   temp.push_back(nums[i]);
if(!st.count(temp)){
    st.insert(temp);
    ans.push_back(temp);
}
   }
    }
         return ans;
    }
};
