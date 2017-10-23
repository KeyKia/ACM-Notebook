/* Ford-Fulkerson O(maxFlow * E)
bi-directional or not changes the c[i][j] & c[j][i]
c[i][j] = c[j][i] = capacity of that pipe
cf [i][j] = c[i][j] - f[i][j]
f[i][j] was unnecessary*/

int n,m,s,t,c[MAX_N][MAX_N],cf[MAX_N][MAX_N],par[MAX_N],maxFlow;
bool mark[MAX_N];

bool bfs() {
    for(int i = 0 ; i < MAX_N ; i++)
        mark[i] = false;
    queue<int>q;
    q.push(s);
    mark[s] = true;
    par[s] = -1;
    while(q.size() > 0) {
        int a = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; i++) {
            if(!mark[i] && cf[a][i] > 0) {
                par[i] = a;
                mark[i] = true;
                q.push(i);
            }
        }
    }
    return mark[t];
}

void fordFulkerson() {
    while(bfs()) {
        vector<int>path;
        int tmp = t;
        while(tmp != -1) {
            path.push_back(tmp);
            tmp = par[tmp];
        }
        reverse(path.begin(),path.end());
        int MIN = INF;
        for(int i = 0 ; i < path.size() -1 ; i++) {
            int a = path[i];
            int b = path[i+1];
            MIN = min(MIN,cf[a][b]);
        }
        for(int i = 0 ; i < path.size() -1 ; i++) {
            int a = path[i];
            int b = path[i+1];
            cf[a][b] -= MIN;
            cf[b][a] += MIN;
        }
        maxFlow += MIN;
    }
}
