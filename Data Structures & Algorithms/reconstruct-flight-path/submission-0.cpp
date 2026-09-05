class Solution {
public:
    unordered_map<string, multiset<string>>adj;
    vector<string> result;
    void eulerian(string node){
        while(!adj[node].empty()){
            string next = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            eulerian(next);
        }
        result.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        eulerian("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
