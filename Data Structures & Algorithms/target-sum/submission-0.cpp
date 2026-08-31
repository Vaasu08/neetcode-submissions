class Solution {
public:
    unordered_map<string, int>dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        int i  =0; 
        int currsum = 0;
        return knapsack(nums, target, i, currsum);
    }
    int knapsack(vector<int>& nums , int target, int i , int currsum){
        string key = to_string(currsum) + "," + to_string(i);
        if(dp.count(key) > 0 ){
           return dp[key];
        }
        if(i == nums.size()){
            return (currsum == target) ? 1 : 0;

        }
        int add = knapsack(nums,target, i + 1, currsum + nums[i]);
        int sub =  knapsack(nums,target, i +1 , currsum - nums[i]);
        return dp[key] = add + sub;
    }

};
