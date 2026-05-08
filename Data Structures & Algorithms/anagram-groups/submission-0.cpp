class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string k=strs[i];
            sort(k.begin(),k.end());
          mp[k].push_back(i);
        }
        vector<vector<string>>ans;
        int j=0;
        for(auto it:mp){
            vector<int>vec;
            vec=it.second;
            ans.push_back({});
            for(int i=0;i<vec.size();i++){
                ans[j].push_back(strs[vec[i]]);
            }
            j++;
        }
        return ans;
    }
};
