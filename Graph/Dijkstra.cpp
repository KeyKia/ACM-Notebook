/* In the Name of ALLAH */

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <fstream>
#include <queue>
#include <cstring>
#include <iomanip>
#include <stack>
#include <map>

using namespace std;

typedef long long ll ;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second

const int N=1e5+10;
const int INF=1000000*1000;
vector <pii> adj[N];
int dis[N],n;
set <pii> s;

void dij(int st){
    for (int i=1;i<=n;i++) dis[i]=INF;
    dis[st]=0;
    for (int i=1;i<=n;i++) s.insert(pii(dis[i],i));
    int u;
    while((int)s.size()){
        u=s.begin()->Y;
        s.erase(s.begin());
        for (int i=0;i<(int)adj[u].size();i++)
            if ( dis[u] + adj[u][i].Y < dis[adj[u][i].X]){
                s.erase(pii(dis[adj[u][i].X], adj[u][i].X));
                dis[adj[u][i].X]=dis[u] + adj[u][i].Y;
                s.insert(pii(dis[adj[u][i].X], adj[u][i].X));
            }
    }
}


int main () {
    //ios_base::sync_with_stdio(false);
    int a,b,w,m;
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        adj[a].pb(pii(b,w));
        adj[b].pb(pii(a,w));
    }

    int st;
    cin>>st;
    dij(st);
    for (int i=1;i<=n;i++) cout<<i<<" : "<<dis[i]<<'\n';

    return 0;
}




