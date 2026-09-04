class DSU{
    public:
    vector<int>parent; 
    vector<int>size;

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i =0;  i < n; i ++){
            parent[i]= i;
            
        }
        
    }
    int find(int node)
    {
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void join(int u , int v){
        u = find(u);
        v = find(v);
        if(u == v){
            return;
        }
        if(size[u]  < size[v]){
            swap(u, v);
        }
        parent[v] = u;
        size[u] += size[v];


    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size(); 
        DSU dsu(n); 
        unordered_map<int, int>mp;
        for(int i =0; i < nums.size(); i++){
            int x = nums[i];
            for(int p = 2; p * p <= x; p++){
                if(x%p == 0){
                    if(mp.count(p)){
                        dsu.join(i, mp[p]);
                    }
                    else{
                        mp[p] = i;
                    }
                }
                while(x %p == 0){
                    x = x/p;
                }
            }
            if(x > 1){
                if(mp.count(x)){
                    dsu.join(i, mp[x]);
                }
                else{
                    mp[x] = i;
                }
            }
        }
        int root = dsu.find(0); 
        for(int i = 1; i < nums.size(); i++){
            if(dsu.find(i) != root){
                return false;
            }
        }
        return true;
    }
};