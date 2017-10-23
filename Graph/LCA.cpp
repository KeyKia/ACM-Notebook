const int MAX_N = 1e5+10;
const int MAX_LOG = 20;

int n,q,par[MAX_N][MAX_LOG],h[MAX_N];
vector<int>v[MAX_N];
bool mark[MAX_N];
// all parents are -1

void dfs(int u,int parent){
    mark[u] = true;
    par[u][0] = parent;
    if(parent != -1)
        h[u] = h[parent]+1;
    for(int i = 1 ; i < MAX_LOG ; i++)
        if(par[u][i-1] != -1)
            par[u][i] = par[par[u][i-1]][i-1];

    for(int i = 0 ; i < v[u].size() ; i++) {
        if(!mark[v[u][i]]) {
            dfs(v[u][i],u);
        }
    }
}
int LCA(int x,int y) {
    if(h[x] < h[y])
        swap(x,y);
    for(int i = MAX_LOG -1 ; i >= 0 ; i--)
        if(par[x][i] != -1 && h[par[x][i]] >= h[y])
            x = par[x][i];
    if(x == y)
        return x;
    for(int i = MAX_LOG-1 ; i >= 0 ; i--)
        if(par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    return par[x][0];
}
