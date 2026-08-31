class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
    
        vector<pair<int, int>> pr(n);
        for(int i =0; i < position.size();i++){
            pr[i] = {position[i],speed[i]};
        }
        sort(pr.begin(), pr.end());
        stack<double>stk;
        for(int i =n-1; i >=0; i--){
            double time = (double)(target - pr[i].first)/pr[i].second;
            if(stk.empty() || time > stk.top()){
                stk.push(time);
            }
            
        }
        return stk.size();
    }
};
