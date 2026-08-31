class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> postime;
        for(int i = 0;i<position.size();i++){
            postime.push_back({position[i], (double)(target - position[i])/speed[i]});
        }
        sort(postime.begin(), postime.end());
        stack<double>Stack;
        for(auto it : postime){
            double time = it.second;
            while(!Stack.empty() && time >= Stack.top()){
                Stack.pop();
            }
            Stack.push(time);

        }
        return Stack.size();
        
    }
};
