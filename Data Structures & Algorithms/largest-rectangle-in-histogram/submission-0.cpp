class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = INT_MIN; 
        stack<pair<int,int>>stack;
        //index + height
        for(int i =0; i < heights.size(); i++){
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                int height = stack.top().second; 
                int index = stack.top().first;
                stack.pop();
                maxarea = max(maxarea, height*(i - index));
                start = index;
            }
            stack.push({start, heights[i]});
        }
        while(!stack.empty()){
            maxarea = max(maxarea , stack.top().second * (n - stack.top().first));
            stack.pop();
        }
        return maxarea;
    }
};
