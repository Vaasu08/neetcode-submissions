class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int>stack; 
        for(int i =0;i < heights.size(); i++){
            while(!stack.empty() && heights[stack.top()] <= heights[i]){
                stack.pop();

            }
            stack.push(i);
        }
        vector<int>result;
        while(!stack.empty()){
            result.push_back(stack.top());
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};