class Solution {
public:
void fxn(int idx, int n, map<int,string>&mp,vector<string>&ans,string digits,string temp){
    if(idx==n){
        ans.push_back(temp);
        return;
    }
    string k=mp[digits[idx]-'0'];
    int x=k.length();
    for(int i=0;i<x;i++){
        temp.push_back(k[i]);
        fxn(idx+1,n,mp,ans,digits,temp);
        temp.pop_back();
    }
    return;
}
    vector<string> letterCombinations(string digits) {
        map<int,string>mp;
       mp[2]="abc";
       mp[3]="def";
       mp[4]="ghi";
       mp[5]="jkl";
       mp[6]="mno";
       mp[7]="pqrs";
       mp[8]="tuv";
       mp[9]="wxyz";
       vector<string>ans;
       int n=digits.length();
       string temp;
       if(n==0) return {};
       fxn(0,n,mp,ans,digits,temp);
       return ans;
    }
};