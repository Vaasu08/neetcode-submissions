class Solution {
public:
    vector<bool>used;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        used.resize(nums.size(),false);
        int target = 0; 
        for(auto it: nums){
            target += it;
        }
        if(target%k!=0){
            return false;
        }
        target = target / k;
        
        return solve(nums, k ,n, 0, target, 0);
    }
    bool solve(vector<int>&nums, int k ,int n, int sum, int target,int i){
        if(k == 0){
            return true;
        }
        if(target == sum){
            return solve(nums, k-1, n, 0, target, 0);
        }
        for(int j = i; j < nums.size(); j ++){
            if(used[j] || sum + nums[j] > target){
                continue;
            }
            used[j] = true; 
            if(solve(nums,k,n,sum + nums[j],target, j+1)){
                return true;
            };
            used[j] = false;
        }
        return false;
    }
};
/* thinking 
all subsets sum will be equal to sum(nums)/k;
15/3 = 5 

*/