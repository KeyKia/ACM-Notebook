int par[MAX_N], n, m;
//Weight , firstNode , seconddNode
vector<pair<int,pair<int,int> > > edges;
vector<pair<int,pair<int,int> > > ans;
vector<int>cc[MAX_N];

void join(int x,int y) {
    x = par[x];
    y = par[y];
    if(cc[y].size() > cc[x].size()) swap(x,y);
    for(int i = 0 ; i < cc[y].size() ; i++) {
        int node = cc[y][i];
        par[node] = x;
        cc[x].push_back(node);
    }
    cc[y].clear();
}

void kruskal() {
    for(int i = 1 ; i <= n ; i++) {
        par[i] = i;
        cc[i].push_back(i);
    }
    sort(edges.begin(), edges.end());
    for(int i = 0 ; i < edges.size() ; i++) {
        int firstNode = edges[i].second.first;
        int secondNode = edges[i].second.second;
        if(par[firstNode] != par[secondNode]) {
            join(firstNode, secondNode);
            ans.push_back(edges[i]);
        }
    }
}
