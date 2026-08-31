class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN; 
        for(auto it : nums){
            result = max(result, it);
        }
        int currmin = 1; 
        int currmax = 1;
        for(int i =0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                currmin = 1;
                currmax = 1;
                continue;
            }
            int temp = currmax*nums[i];
            currmax = max(currmax * nums[i], max(currmin * nums[i] , nums[i]));
            currmin = min(temp, min(currmin * nums[i] , nums[i]));
            result = max(result, max(currmax, currmin));
        }
        return result;
    }
};
