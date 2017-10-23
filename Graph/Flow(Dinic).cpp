//Dinic O(V^2*E)
struct Edge {
    int to,reverseIndex,cap,flow;
};

int n,m,s,t,maxFlow,dis[MAX_N];
vector<Edge>g[MAX_N];

bool bfs() {
    for(int i = 0 ; i < MAX_N ; i++)
        dis[i] = INF;
    queue<int>q;
    q.push(s);
    dis[s] = 0;
    while(q.size() > 0) {
        int v = q.front();
        q.pop();
        for(int i = 0 ; i < g[v].size() ; i++) {
            Edge x = g[v][i];
            int u = x.to;
            if(dis[u] == INF && x.flow < x.cap) {
                dis[u] = dis[v]+1;
                q.push(u);
            }
        }
    }
    return (dis[t] != INF);

}

int dfs(int v,int f) {
    if(v == t)
        return f;
    for(int i = 0 ; i < g[v].size() ; i++) {
        Edge &x = g[v][i];
        int u = x.to;
        if(x.cap <= x.flow) continue;
        if(dis[u] == dis[v]+1) {
            int tmp = dfs(u,min(f,x.cap-x.flow));
            if(tmp > 0) {
                x.flow += tmp;
                g[u][x.reverseIndex].flow -= tmp;
                return tmp;
            }
        }
    }
    return 0;
}

void dinic() {
    while(bfs()) {
        while(int tmp = dfs(s,INF))
            maxFlow += tmp;
    }

}
