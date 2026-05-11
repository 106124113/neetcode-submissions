class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++)
            mp[t[i]]++;
        int count = m;
        int i = 0, j = 0;
        int idx1 = -1;
        int mini = INT_MAX;

        while (j < n) {
            if (mp[s[j]] > 0)
                count--;
            mp[s[j]]--;
            while (count == 0) {
                if (j - i + 1 < mini) {
                    mini = j - i + 1;
                    idx1 = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    count++;
                i++;
            }
            j++;
        }

        if (mini == INT_MAX)
            return "";

        return s.substr(idx1, mini);
    }
};