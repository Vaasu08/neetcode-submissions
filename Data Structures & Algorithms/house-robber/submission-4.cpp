class Solution {
public:
    vector<int>dp;
    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);
        int n = nums.size();
        return solve(nums, 0, n);
    }
    int solve(vector<int>& nums, int i , int n){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i]; 
        }
        
        return dp[i] = max(nums[i] + solve(nums,i+2, n), solve(nums,i+1, n));
    }
};
