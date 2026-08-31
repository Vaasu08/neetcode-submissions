class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxX = INT_MIN;
        int maxY = INT_MIN; 
        int maxZ = INT_MIN;
        for(auto &t: triplets){
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]){
                continue;
            }
             maxX = max(t[0], maxX);
            maxY = max(t[1], maxY);
            maxZ = max(t[2], maxZ);
            
        }
        vector<int> ans = {maxX, maxY, maxZ};
return ans == target;
    }
};
