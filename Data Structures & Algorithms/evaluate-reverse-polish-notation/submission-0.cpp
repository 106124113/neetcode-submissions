class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int>st;
      int n=tokens.size();
      int ans=0;
      for(int i=0;i<n;i++){
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            int sol;
            if(tokens[i]=="+") sol=a+b;
            else if(tokens[i]=="-") sol=b-a;
            else if(tokens[i]=="*") sol=a*b;
           else sol=b/a;
          st.push(sol);
        }
        else st.push(stoi(tokens[i]));
      }
      return st.top();  
    }
};
