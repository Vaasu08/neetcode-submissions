class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>stk;
        for(int i = 0;i  < asteroids.size();i ++){
            bool isAlive = true;
            while(!stk.empty() && stk.top() > 0 && asteroids[i] < 0){
                if(abs(asteroids[i]) == abs(stk.top())){
                    isAlive = false;
                    stk.pop();
                    break;
                }
                else if(abs(asteroids[i]) < abs(stk.top())){
                    isAlive = false;
                    break;
                }
                if(abs(asteroids[i]) > abs(stk.top())){
                    isAlive = true;
                    stk.pop();
                }
                
            }
            if(isAlive == true){
                stk.push(asteroids[i]);
            }
        }
        vector<int> ans;

        while(!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
/* thinking ...
using flag to check if the asteroid is still alive or not 
flag becomes false if the asteroids destroyed
if the flag is true that means the asteroid is still fighting
if the asteroid takes another asteroid with itself while collision still the flag becomes false;

 */