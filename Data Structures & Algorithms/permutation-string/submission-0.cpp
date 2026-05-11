class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        map<char,int>mp1,mp2;
        for(int i=0;i<n;i++) mp1[s1[i]]++;
        int i=0,j=0;
        while(j<m){
            if(j-i+1>n){
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0) mp2.erase(s2[i]);
                i++;
            }
mp2[s2[j]]++;
if(mp1==mp2) return true;
j++;
        }
        return false;
    }
};
