class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size(),m=matrix[0].size();
       int low=0,high=n*m-1;
       while(low<=high){
       int idx=(low+high)/2;
       int i=idx/m,j=idx%m;
    if(matrix[i][j]==target) return true;
    else if(matrix[i][j]>target){
        high=idx-1;
    }
    else low=idx+1;
       }
       return false;
    }
};
