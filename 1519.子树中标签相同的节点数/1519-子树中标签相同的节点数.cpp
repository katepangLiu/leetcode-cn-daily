class Solution {
public:
    vector<vector<int>> G;
    string labels;
    vector<int> res;
    map<char, int> mp;
    
    void DFS(int u, int pa = -1){
        res[u] -= mp[labels[u]];
        mp[labels[u]] += 1;
        for(int v : G[u]) if(v != pa) DFS(v, u);
        res[u] += mp[labels[u]];
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        G.clear();
        G.resize(n, {});
        for(auto e : edges){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        this->labels = labels;
        res.clear();
        res.resize(n, 0);
        mp.clear();
        DFS(0);
        return res;
    }
};