class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                matrix[i][j] +=matrix[i][j-1];
            }
        }
        for(int j =0;j<m;j++){
            for(int i = 1;i<n;i++){
                matrix[i][j] += matrix[i-1][j];
            }
        }
        prefix = matrix;
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r = 0;
        int s = 0;
        int t = 0;
        int ans = prefix[row2][col2];
        if(row1-1 >=0){
            r = prefix[row1-1][col2];
        }
        if(col1-1 >= 0){
            s = prefix[row2][col1-1];
        }
        if(row1 -1 >=0 && col1-1>=0){
            t = prefix[row1-1][col1-1];
        }
        int extra =  r + s - t;
        return ans - extra;
    }
};