class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(j<n){
            if(mp.count(s[j])){
                int k=i;
                i=mp[s[j]]+1;
                while(k<i){
 mp.erase(s[k]);
k++;
                }
            }
            mp[s[j]]=j;
              ans=max(ans,j-i+1);
j++;
        }
        // ans=max(ans,j-i+1);
        return ans;
    }
};
