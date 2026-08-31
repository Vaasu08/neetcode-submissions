class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stk;
        int n = asteroids.size();
        for(int i = 0 ;i < asteroids.size(); i++){
            if(stk.empty() || asteroids[i] > 0){
                stk.push(asteroids[i]);
            }
            else{
                while(true){
                    
                    int top = stk.top();
                    if(top < 0){
                        stk.push(asteroids[i]);
                        break;
                    }
                    else if(top == -asteroids[i]){
                        stk.pop();
                        break;
                    }
                    else if(top > -asteroids[i]){
                        break;
                    }
                    else{
                        stk.pop();
                        if(stk.empty()){
                            stk.push(asteroids[i]);
                            break;
                        }
                    }
                    
                }
            }
        }
        vector<int>result(stk.size());
        for(int i = stk.size() -1 ;i>=0;i--){
            result[i] = stk.top();
            stk.pop();
        }
        return result;

    }
};
// [5,5,5] 