class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        queue<int>que;
        vector<vector<int>>adj(n); 
        if(edges.size() == 0){
            return {0};
        }
        for(auto edge : edges){
            int a = edge[0];
            int b = edge[1]; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>degree(n);
        for(int i =0; i < adj.size(); i++){
            for(auto it : adj[i]){
                degree[i]++;
            }
        }
        for(int i =0; i < adj.size(); i++){
            if(degree[i] == 1){
                que.push(i);
            }
        }
        int remainingnodes = n; 
        while(remainingnodes > 2){
            remainingnodes = remainingnodes - que.size();
            int size = que.size();
            while(size--){
                auto i = que.front(); 
                que.pop(); 
                for(auto it : adj[i]){
                    degree[it]--; 
                    if(degree[it] == 1){
                        que.push(it);
                    }
                }
            }

        }
        vector<int>result;
        while(!que.empty()){
            int i = que.front(); 
            que.pop();
            result.push_back(i);
        }
        return result;
    }
    
};