class Solution {
public:
    vector<int>dp;
    int rob(vector<int>& nums) {
        dp.resize(nums.size()  + 1, -1);
        int n = nums.size(); 
        return solve(nums,n, 0);
    }
    int solve(vector<int>& nums, int n, int i){
        
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        return dp[i] = max(nums[i] + solve(nums, n , i + 2), solve(nums , n , i+ 1));
    }
};

/* thinking...
i+2 should be less than n;
for loop for i; till i + 2 < n
*/