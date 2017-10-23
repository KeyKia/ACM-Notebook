int n, height[MAX_N], par[MAX_N];
vector<int>v[MAX_N];
bool mark[MAX_N];


void dfs(int u) {
    mark[u] = true;
    for(int i = 0 ; i < v[u].size() ; i++)
        if(!mark[v[u][i]]) {
            par[v[u][i]] = u;
            height[v[u][i]] = height[u]+1;
            dfs(v[u][i]);
        }
}
