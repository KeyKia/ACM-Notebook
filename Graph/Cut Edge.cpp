int n, m, par[MAX_N], low[MAX_N], height[MAX_N] ;
bool mark[MAX_N];
vector<int>v[MAX_N];
vector<pair<int,int> >articulationBridges;
//dfs(1,0)
void dfs(int u, int h) {
    mark[u] = true;
    low[u] = h;
    height[u] = h;
    for(int i = 0 ; i < v[u].size() ; i++) {
        int node = v[u][i];
        if(!mark[node]) {
            par[node] = u;
            dfs(node, h+1);
            if(low[node] > height[u])
                articulationBridges.push_back(make_pair(u,node));
            low[u] = min(low[u], low[node]);
        }
        else if(node != par[u] && height[node] < height[u])
            low[u] = min(low[u], height[node]);

    }
}
