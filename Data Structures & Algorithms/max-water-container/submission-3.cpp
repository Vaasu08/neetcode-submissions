class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left =0;
        int maxarea = 0; 
        int right = heights.size()-1;
        while(right > left){
            int h = min(heights[right],heights[left]);
            int area = h*(right - left);
            if(heights[left] > heights[right]){
                right --;
            }
            else{left++;}
            if(area >= maxarea){
                maxarea = area;
            }
            
        }
        return maxarea;
    }
};
