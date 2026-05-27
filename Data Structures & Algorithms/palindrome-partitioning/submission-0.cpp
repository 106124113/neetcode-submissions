class Solution {
public:
bool ispalindrome(string s){
    string x=s;
    reverse(x.begin(),x.end());
    if(x==s) return true;
    return false;
}
void fxn(int idx,int n,vector<string>&curr,string s,vector<vector<string>>&ans){
    if(idx==n){
        ans.push_back(curr);
        return;
    }
    for(int i=idx;i<n;i++){
        if(ispalindrome(s.substr(idx,i-idx+1))){
            curr.push_back(s.substr(idx,i-idx+1));
            fxn(i+1,n,curr,s,ans);
            curr.pop_back();
        }
    }
    return;
}
    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
         vector<string>curr;
         int n=s.length();
         fxn(0,n,curr,s,ans);
         return ans;
    }
};