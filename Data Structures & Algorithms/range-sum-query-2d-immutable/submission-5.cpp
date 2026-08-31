class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i =0;i<n;i++){
            for(int j = 1;j<m;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int j = 0;j<m;j++){
            for(int i = 1;i<n;i++){
                matrix[i][j] += matrix[i-1][j];
            }
        }
        prefix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int p = 0;
        int q = 0;
        int r = 0;
        if(row1-1 >=0){
            p = prefix[row1-1][col2];
        }
        if(col1-1 >= 0){
            q = prefix[row2][col1-1];
        }
        if(col1 -1>=0 && row1-1 >=0){
            r = prefix[row1-1][col1-1];
        }
        int ans = prefix[row2][col2];
        int extra =  p +q - r;
        return ans - extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */