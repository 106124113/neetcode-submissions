class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     int high=*max_element(piles.begin(),piles.end());
     int low=1;
     int n=piles.size();
     while(low<=high){
        int mid=(low+high)/2;
        int ans=0;
        for(int i=0;i<n;i++){
ans+=ceil(piles[i]/(double)mid);
        }
        if(ans<=h) high=mid-1;
        else low=mid+1;
     }  
return low;
    }
};
