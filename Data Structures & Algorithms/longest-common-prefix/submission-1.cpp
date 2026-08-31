class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool match = true;
        string res;
        for(int i = 0;i<strs[0].size();i++){
            char ch = strs[0][i];
            
            for(int j = 1;j<strs.size();j++){
                if(i >= strs[j].size() || ch != strs[j][i]){
                    match = false;
                    break;
                }
            }
            if(match == false){
                break;
            }else{
                    res = res + ch;
            }
            
        }
        return res;
        
    }
};