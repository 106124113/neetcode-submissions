class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<char,int>mp;
       int i=0,j=0;
       int maxi=0;
       int ans=0;
       while(j<n){
        // int len=j-i+1;
        mp[s[j]]++;
        maxi=max(maxi,mp[s[j]]);
while((j-i+1)-maxi>k){
mp[s[i]]--;
i++;
maxi=0;
for(auto it:mp) maxi=max(maxi,it.second);
}
ans=max(ans,j-i+1);
j++;
       }
       return ans;
    }
};
