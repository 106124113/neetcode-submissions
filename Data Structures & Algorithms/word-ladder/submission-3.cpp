class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        priority_queue<pair<int,pair<string,vector<int>>>,vector<pair<int,pair<string,vector<int>>>>,greater<pair<int,pair<string,vector<int>>>>>q;
        q.push({0,{beginWord,{}}});
        int n=wordList.size();
        map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[wordList[i]]=i;
        }
        int len=beginWord.size();
        int mini=INT_MAX;
        while(!q.empty()){
            int time=q.top().first;
            string str=q.top().second.first;
            vector<int>t=q.top().second.second;
            q.pop();
            if(str==endWord){
               return time+1;
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
q.push({time+1,{x,temp}});
                    }
                    }
                }
            }
        }
       return 0;
    }
};
