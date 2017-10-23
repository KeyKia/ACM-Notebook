ll n,m,dis[MAX_N];
//first Node, second Node, weight
vector<pair<pair<ll,ll>,ll > > edges;
bool negativeCycle;

void bellmanFord() {
    for(int i = 0 ; i < MAX_N ; i++)
            dis[i] = INF;
    dis[1] = 0;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j < edges.size() ; j++) {
            ll a = edges[j].first.first;
            ll b = edges[j].first.second;
            ll wieght = edges[j].second;
            if(dis[a] + weight < dis[b])
                dis[b] = dis[a]+wieght;
        }
    }
    for(int j = 0 ; j < edges.size() ; j++) {
        ll a = edges[j].first.first;
        ll b = edges[j].first.second;
        ll wieght = edges[j].second;
        if(dis[a] + weight < dis[b])
            negativeCycle = true;
    }
}

/*
we can solve 
m inequalities like : x(i) - x(j) <= c
we make one node for each x(i)
we make a source with edge weight 0 to all other nodes
we put a edge from j to i with weight c
bellman ford from source
x[i] is dis[i]
*/

