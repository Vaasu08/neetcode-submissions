class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool contains1 = false;
        int n = nums.size();
        int idx;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                contains1 = true;
            }
            if(nums[i] > n || nums[i] <= 0){
                nums[i] = 1;
            }
        }
        if(contains1 == false){
            return 1;
        }
        for(int i = 0;i<n;i++){
            

            int x = abs(nums[i]);
            idx = x-1;
            if(nums[idx] < 0){
                continue;
            }
            nums[idx]*= -1;
        }
        for(int i = 0;i<n;i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        return n+1;
        
    }
};