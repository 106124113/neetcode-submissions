class Solution {
public:
    bool isPalindrome(string s) {
       int n=s.length();
       string k="";
       for(int i=0;i<s.length();i++){
        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' ||s[i]=='8' || s[i]=='9') k.push_back(s[i]);
        if(s[i]>=97 && s[i]<=122) k.push_back(s[i]);
     else   if(s[i]>=65 && s[i]<=90 ) k.push_back(s[i]+32);
       } 
       int x=k.length();
       for(int i=0;i<x/2;i++){
        if(k[i]!=k[x-i-1]) return false;
       }
       return true;
    }
};
