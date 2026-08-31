class Solution {
public:
    bool validbox(vector<vector<char>>& board, int sc,int ec, int sr,int er){
        unordered_set<int>st;
        for(int i = sc;i<=ec;i++){
            for(int j = sr;j<=er;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(st.find(board[i][j]) != st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i =0;i<9;i++){
            unordered_set<int>st;
            for(int j =0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(st.find(board[i][j]) !=st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        for(int j =0;j<9;j++){
            unordered_set<int>st;
            for(int i=0;i<9;i++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(st.find(board[i][j]) !=st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        
        for(int sc =0; sc<9;sc+=3){
            int ec = sc+2;
            for(int sr = 0;sr<9;sr+=3){
                int er = sr + 2;
                if(!validbox(board,sc,ec,sr,er)){
                    return false;
                }
            }
        }
        return true;
    }
};