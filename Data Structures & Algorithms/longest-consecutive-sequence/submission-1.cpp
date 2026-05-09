class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        // if(st.size()==0) return ans
        for(auto it:st){
if(!st.count(it-1)){
    int x=it,c=1;
    while(st.count(x+1)){
        x++;
        c++;
    }
    ans=max(ans,c);
}
        }
        return ans;
    }
};
