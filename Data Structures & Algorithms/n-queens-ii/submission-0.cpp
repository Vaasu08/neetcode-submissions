class Solution {
public:
    int n;
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'*'));
        int count = 0;
        dfs(n,0,board,count);
        return count;
    }
    bool isValid(vector<string>&board,int row, int col){
        for(int i = row-1; i >=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row-1,j = col-1; i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row-1, j = col+1; i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void dfs(int n, int row, vector<string>&board,int& count){
        this->n = n;
        if(row >= n){
            count++;
            return;
        }
        for(int col = 0; col < n;col++){
            if(isValid(board,row,col)){
                board[row][col] = 'Q';
                dfs(n,row+1,board,count); 
                board[row][col] = '*';
            }
        }
    }
};