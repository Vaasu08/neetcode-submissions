class Solution {
public:
    vector<vector<int>>dp;
    int combinationSum4(vector<int>& nums, int target) {
        int n  = nums.size();
        dp.resize(target +1 , vector<int>(n+1, -1));

        return solve(nums, target, n, 0);

    }
    int solve(vector<int>& nums, int target, int n,int i){
        
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        if(i >= n){
            return 0;
        }
        if(dp[target][i] != -1){
            return dp[target][i];
        }
        
        int take = solve(nums, target - nums[i],n,0);
        int nottake = solve(nums, target,n, i+1);
        return dp[target][i] = take + nottake;
    }
    
};
/*thinking...

*/
