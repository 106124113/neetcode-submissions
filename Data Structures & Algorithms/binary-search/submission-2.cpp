class Solution {
public:
    int search(vector<int>& nums, int target) {
     int n=nums.size();
     int i=0,j=n-1;
     while(i<=j){
        int mid=(i+j)/2;
        cout<<mid;
        if(nums[mid]>target) j--;
        else if(nums[mid]<target) i++;
        else return mid;
     }   
     return -1;
    }
};
