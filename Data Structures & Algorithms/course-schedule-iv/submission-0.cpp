class Solution {
public:
    void dfs(int source, int node, vector<bool>&Visited, vector<vector<bool>>&isReachable,vector<vector<int>>&adj){
        Visited[node] = true;
        for(auto it : adj[node]){
            if(!Visited[it]){
                isReachable[source][it] = true;
                dfs(source, it, Visited, isReachable, adj);
            }
        }


    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        for(int i =0; i < prerequisites.size();i++)
        {
            int course1 = prerequisites[i][0];
            int course2 = prerequisites[i][1]; 
            adj[course1].push_back(course2);
        }
        vector<vector<bool>>isReachable(numCourses, vector<bool>(numCourses,false));
        for(int i =0; i < n; i++){
            vector<bool>Visited(n); 
            dfs(i, i , Visited, isReachable, adj);
        }
        vector<bool>result;
        for(auto it: queries){
            result.push_back(isReachable[it[0]][it[1]]);
        }
        return result;

    }
    
};