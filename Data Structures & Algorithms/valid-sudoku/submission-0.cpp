class Solution {
public:
bool validRow(int i, vector<vector<char>>& board, int m) {
    set<char> s;

    for(int j = 0; j < m; j++) {
        if(board[i][j] == '.') continue;

        if(s.count(board[i][j])) return false;

        s.insert(board[i][j]);
    }

    return true;
}

bool validCol(int j, vector<vector<char>>& board, int n) {
    set<char> s;

    for(int i = 0; i < n; i++) {
        if(board[i][j] == '.') continue;

        if(s.count(board[i][j])) return false;

        s.insert(board[i][j]);
    }

    return true;
}

    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
           if(!validRow(i,board,m)){
            return false;
           }
        }
       for(int i=0;i<m;i++){
           if(!validCol(i,board,n)){
            return false;
           }
        }
        for(int br=0;br<n;br+=3){
            for(int bc=0;bc<m;bc+=3){
        set<char>s;
       for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[br+i][bc+j]=='.') continue;
            if(s.count(board[br+i][bc+j])) return false;
            s.insert(board[br+i][bc+j]);
        }
       }
            }
        }
        return true;
    }
};
