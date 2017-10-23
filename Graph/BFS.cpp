int n, m, par[MAX_N], height[MAX_N];
vector<int>v[MAX_N];
bool mark[MAX_N];

void bfs(int start) {
    mark[start] = true;
    queue<int>q;
    q.push(start);

    while(q.size() > 0) {
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(int i = 0 ; i < v[node].size() ; i++) {
            int neigh = v[node][i];
            if(!mark[neigh]) {
                mark[neigh] = true;
                par[neigh] = node;
                height[neigh] = height[node] + 1;
                q.push(neigh);
            }
        }
    }
}
