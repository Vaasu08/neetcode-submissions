class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int x = 0;
        int y = 0;
        int n = word1.size();
        int m = word2.size();
        int t = n+m;
        for(int i =0;i<t;i++){
            if(x < word1.size()){
                res += word1[x];
                x++;
            }
            if(y < word2.size()){
                res+=word2[y];
                y++;
            }
        }
        return res;
    }
};