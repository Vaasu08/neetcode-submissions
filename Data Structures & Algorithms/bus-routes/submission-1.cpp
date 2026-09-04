class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        unordered_map<int, vector<int>>adj;
        if(source == target){
            return 0;
        }
        for(int route = 0; route < routes.size(); route++){
            for(auto stops: routes[route]){
                adj[stops].push_back(route);
            }
        }
        queue<int>que;
        vector<int>Visited(5001, false);
        for(auto route : adj[source]){
            que.push(route);
            Visited[route] = true;
        }
        int count = 1;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                auto it = que.front(); 
                que.pop();
                for(auto stop : routes[it]){
                    if(stop == target){
                        return count;
                    }
                    for(auto nextRoute : adj[stop]){
                        if(Visited[nextRoute] == true){
                            continue;
                        }
                        Visited[nextRoute] = true;
                        que.push(nextRoute);
                    }
                }
                
            }
            count++;
        }
        return -1;
    }
};