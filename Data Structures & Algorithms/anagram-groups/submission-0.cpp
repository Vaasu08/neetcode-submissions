class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        if(strs.size() == 0){
            return res;
        }
        unordered_map<string,vector<string>>counter; 
        for(auto it: strs){
            string s; 
            s = it;
            sort(s.begin(),s.end());
            counter[s].push_back(it);
            
        }
        for(auto it:counter){
            res.push_back(it.second);
        }
        return res;
    }

};
