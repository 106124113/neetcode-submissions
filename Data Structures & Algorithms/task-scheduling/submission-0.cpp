class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;

        for(char ch : tasks){
            mp[ch]++;
        }

        priority_queue<int> pq;

        for(auto it : mp){
            pq.push(it.second);
        }

        int ans = 0;

        while(!pq.empty()){

            vector<int> temp;
            int cnt = 0;

            while(!pq.empty() && cnt < n + 1){

                int x = pq.top();
                pq.pop();

                x--;

                if(x > 0) temp.push_back(x);

                cnt++;
            }

            for(int x : temp){
                pq.push(x);
            }

            if(pq.empty())
                ans += cnt;
            else
                ans += n + 1;
        }
        return ans;
    }
};