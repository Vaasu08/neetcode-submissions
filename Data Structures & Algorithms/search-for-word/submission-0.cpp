class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>st(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dfs(board,word,0,i,j,st)){
                    return true;
                }
            }
        }
        return false; 
    }
    bool dfs(vector<vector<char>>& board,string& word,int i,int r,int c,vector<vector<int>>&st){
        if(i == word.size()){
            return true;
        }
        int n = board.size();
        int m = board[0].size();
        if(r<0 || c<0 || r>=n || c>=m || board[r][c] != word[i]){
            return false;
        }
        if(st[r][c] == 1){
            return false;
        }
        st[r][c] = 1;
        bool result = dfs(board,word,i+1,r+1,c,st) || dfs(board,word,i+1,r-1,c,st) || dfs(board,word,i+1,r,c+1,st) || dfs(board,word,i+1,r,c-1,st);
        st[r][c] = 0;
        return result;
    }
};
