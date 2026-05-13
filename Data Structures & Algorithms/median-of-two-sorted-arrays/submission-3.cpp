class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int k=0;
        if((m+n)%2==0){
            k=(m+n)/2;
        }
        else{
            k=(m+n)/2+1;
        }
        cout<<k<<" ";
        double ans;
        int i=0,j=0;
while(i<n && j<m && k>0){
    k--;
    if(nums1[i]<nums2[j]){
        cout<<nums1[i]<<" ";
        if(k==0) ans=nums1[i];
        i++;
    }
    else if(nums1[i]>nums2[j]){
         cout<<nums2[j]<<" ";
        if(k==0) ans=nums2[j];
        j++;
    }
    else{
       if(k==0) ans=nums2[j];
       j++;
       k--;
          if(k==0) ans=nums1[i];
          i++;
    }
}
while(i<n && k>0){
    k--;
     if(k==0) ans=nums1[i];
        i++;
}
while(j<m && k>0){
    k--;
    if(k==0) ans=nums2[j];
    j++;
}
cout<<ans;
if((m+n)%2==0){
int nextElement;

if(i<n && (j>=m || nums1[i] < nums2[j]))
    nextElement = nums1[i];
else
    nextElement = nums2[j];

ans = (ans + nextElement) / 2.0;
}
return ans;
    }
};
