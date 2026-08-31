class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;
        unordered_map<int,int>mp;
        vector<vector<int>>sup(n + 1);
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            sup[it.second].push_back(it.first);
        }
        int x = 0;
        for(int i = n;i>=0 && res.size()<k;i--){
            if(!sup[i].empty()){
                res.insert(res.end(), sup[i].begin(), sup[i].end());
            }
            
        }
        return res;
    }
};
