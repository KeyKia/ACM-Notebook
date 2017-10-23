//a b deg[b]++ g[a].push_back(b)
//start from deg[i] == 0
int n,m, deg[MAX_N];
vector<int>g[MAX_N];
vector<int>topologicalSort;
bool mark[MAX_N];
void tSort(int v) {
    mark[v] = true;
    for(int i = 0 ; i < g[v].size() ; i++)
        if(!mark[g[v][i]])
            tSort(g[v][i]);
    topologicalSort.push_back(v);
}

