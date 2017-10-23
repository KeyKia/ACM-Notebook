int n, m, par[MAX_N], low[MAX_N], height[MAX_N],cnt = 1;
bool mark[MAX_N],markV[MAX_N];
vector<int>v[MAX_N];
vector<int>articulationPoints;
vector<pair<int,int> > tmp_find,bcc[MAX_N];


void FIND(pair<ll,ll>x) {
    while(tmp_find.size() > 0) {
        pair<ll,ll>y = tmp_find[tmp_find.size()-1];
        tmp_find.pop_back();
        bcc[cnt].push_back(y);
        if(y == x || (y.first == x.second && y.second == x.first))
            break;
    }
    cnt++;
}
//dfs(1,0)
void dfs(int u, int h) {
    mark[u] = true;
    low[u] = h;
    height[u] = h;
    int childCount = 0;
    bool isArticulation = false;
    for(int i = 0 ; i < v[u].size() ; i++) {
        int node = v[u][i];
        if(!mark[node]) {
            tmp_find.push_back(make_pair(u,node));
            par[node] = u;
            dfs(node, h+1);
            childCount++;
            if(low[node] >= height[u]) {
                FIND(make_pair(u,node));
                isArticulation = true;
            }
            low[u] = min(low[u], low[node]);
        }
        else if(node != par[u] && height[node] < height[u]) {
            tmp_find.push_back(make_pair(u,node));
            low[u] = min(low[u], height[node]);
        }

    }
    if((par[u] != 0 && isArticulation) || (par[u] == 0 && childCount > 1)) {
        articulationPoints.push_back(u);
        markV[u] = true;
    }
}
