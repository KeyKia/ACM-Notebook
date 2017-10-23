ll n,m,dis[MAX_N],par[MAX_N];
//weight, node
vector<pair<ll,ll> >v[MAX_N];
//weight, node
set<pair<ll,ll> >s;

void dijekstra(int start) {
    for(int i = 1 ; i <= n ; i++) dis[i] = INF;

    dis[start] = 0;
    par[start] = -1;

    s.insert(make_pair(0,start));
    while(s.size() > 0) {
        pair<ll,ll>a = *s.begin();
        s.erase(*s.begin());
        ll distance = a.first;
        ll node = a.second;
        for(int i = 0 ; i < v[node].size() ; i++) {
            ll edgeWeight = v[node][i].first;
            ll neigh = v[node][i].second;
            if(distance + edgeWeight < dis[neigh]) {
                s.erase(make_pair(dis[neigh], neigh));
                dis[neigh] = distance + edgeWeight;
                par[neigh] = node;
                s.insert(make_pair(dis[neigh], neigh));
            }
        }
    }
}
