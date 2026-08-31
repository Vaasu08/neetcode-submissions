class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        vector<int>rec(4,0);
        for(auto it : matchsticks){
            sum+=it;
        }
        if(sum%4 != 0 ){
            return false;
        }
        int value = sum/4;
        return dfs(matchsticks,0,value,rec);
    }
    bool dfs(vector<int>&matchsticks, int i, int value,vector<int>&rec){
        if(i == matchsticks.size()){
            return true;
        }
        for(int j = 0;j < 4; j++){
            if(rec[j] + matchsticks[i] <= value){
                rec[j]+=matchsticks[i];
                if(dfs(matchsticks,i+1,value,rec)){
                    return true;
                }
                rec[j]-=matchsticks[i];
                
            }
            
        }
        return false;
    }
};