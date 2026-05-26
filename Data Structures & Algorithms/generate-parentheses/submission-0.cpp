class Solution {
public:
bool isvalid(string s){
    int k=s.length();
    int i=0;
    stack<char>st;
    while(i<k){
        if(s[i]=='(') st.push(s[i]);

        else {
            if(st.empty()) return false;
            st.pop();
        }
        i++;
    }
    if(!st.empty()) return false;
    return true;
}
    void fxn(int n,
             vector<string>& ans,
             string &temp) {
if(temp.size()==2*n){
    if(isvalid(temp))ans.push_back(temp);
    return;
}
temp.push_back('(');
fxn(n,ans,temp);
temp.pop_back();
temp.push_back(')');
fxn(n,ans,temp);
temp.pop_back();
return;
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string temp;

        fxn(n,ans, temp);

        return ans;
    }
};