class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<vector<int>>result;
        vector<int>subset;
        dfs(nums, mp,subset,result);
        return result;
    }
    void dfs(vector<int>nums,unordered_map<int,int>mp,vector<int>subset,vector<vector<int>>&result){
        if(subset.size() == nums.size()){
            result.push_back(subset); 
            return;
        }
        for(auto &it: mp)
        {
            if(it.second > 0){
                it.second--;
                subset.push_back(it.first);
                dfs(nums, mp,subset,result);
                subset.pop_back();
                it.second++;
            }
        }

    }
};