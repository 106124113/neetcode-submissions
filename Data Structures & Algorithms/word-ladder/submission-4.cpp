class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,vector<int>>>q;
        q.push({beginWord,{}});
        int n=wordList.size();
        map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[wordList[i]]=i;
        }
        int len=beginWord.size();
        int mini=INT_MAX;
        while(!q.empty()){
            string str=q.front().first;
            vector<int>t=q.front().second;
            q.pop();
            if(str==endWord){
               return t.size()+1;
            }
            for(int i=0;i<len;i++){
                for(char ch='a';ch<='z';ch++){
                    if(ch==str[i]) continue;
                    string x=str;
                    x[i]=ch;
                    if(mp.find(x)!=mp.end()){
                        int flag=0;
                    for(int j=0;j<t.size();j++){
                        if(wordList[t[j]]==x){
flag=1;
break;
                        }
                    }
                    if(flag==0){
                      vector<int> temp=t;
temp.push_back(mp[x]);
q.push({x,temp});
                    }
                    }
                }
            }
        }
        return 0;
    }
};
