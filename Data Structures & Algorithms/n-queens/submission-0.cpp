class Solution {
public:

bool isvalid(vector<int>& temp,int row,int col){

    for(int i=0;i<row;i++){

        if(temp[i]==col) return false;

        if(abs(temp[i]-col)==abs(i-row)) return false;
    }

    return true;
}

void fxn(int idx,int n,vector<vector<string>>&ans,vector<int>&temp){

    if(temp.size()==n) {

        vector<string> y;

        for(int i=0;i<n;i++){

            string x(n,'.');

            x[temp[i]]='Q';

            y.push_back(x);
        }

        ans.push_back(y);

        return;
    }

    for(int i=0;i<n;i++){

        if(isvalid(temp,idx,i)){

            temp.push_back(i);

            fxn(idx+1,n,ans,temp);

            temp.pop_back();
        }
    }

    return;
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;

    vector<int> temp;

    fxn(0,n,ans,temp);

    return ans;
}
};