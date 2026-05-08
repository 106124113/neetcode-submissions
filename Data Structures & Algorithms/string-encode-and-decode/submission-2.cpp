class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for(string &s : strs) {
            res += to_string(s.length()) + '#';
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while(i < s.length()) {

            int j = i;

            // find '#'
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));

            j++; // move after '#'

            ans.push_back(s.substr(j, len));

            i = j + len;
        }

        return ans;
    }
};
