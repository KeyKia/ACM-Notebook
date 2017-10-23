//IN THE NAME OF GOD
//BENYAM1N
#include <queue>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX_N = 100+10;
const int INF = 1e9;

struct Edge {
  int to, f, cap, cost, rev;
};

//0 base
int n,m,s,t;
int prio[MAX_N], curflow[MAX_N], prevedge[MAX_N], prevnode[MAX_N], q[MAX_N], pot[MAX_N];
bool inqueue[MAX_N];
vector<Edge> graph[MAX_N];

void CLEAR() {
	for(int i = 0 ; i < MAX_N ; i++) {
		prio[i] = curflow[i] = prevedge[i] = prevnode[i] = q[i] = pot[i] = inqueue[i] = 0;
		graph[i].clear();
	}

}





void addEdge(int s, int t, int cap, int cost) {
  Edge a = {t, 0, cap, cost, graph[t].size()};
  Edge b = {s, 0, 0, -cost, graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

void bellmanFord(int s, int dist[]) {
  for(int i = 0 ;  i< MAX_N ; i++)
  	dist[i] = INF;
  dist[s] = 0;
  int qt = 0;
  q[qt++] = s;
  for (int qh = 0; (qh - qt) % n != 0; qh++) {
    int u = q[qh % n];
    inqueue[u] = false;
    for (int i = 0; i < (int) graph[u].size(); i++) {
      Edge &e = graph[u][i];
      if (e.cap <= e.f) continue;
      int v = e.to;
      int ndist = dist[u] + e.cost;
      if (dist[v] > ndist) {
        dist[v] = ndist;
        if (!inqueue[v]) {
          inqueue[v] = true;
          q[qt++ % n] = v;
        }
      }
    }
  }
}

pii minCostFlow(int s, int t, int maxf) {
// bellmanFord can be safely commented if edges costs are non-negative
//bellmanFord(s, pot);
  int flow = 0;
  int flowCost = 0;
  while (flow < maxf) {
    priority_queue<ll, vector<ll>, greater<ll> > q;
    q.push(s);
    for(int i = 0 ; i < MAX_N ; i++)
    	prio[i] = INF;
    prio[s] = 0;
    curflow[s] = INF;
    while (!q.empty()) {
      ll cur = q.top();
      int d = cur >> 32;
      int u = cur;
      q.pop();
      if (d != prio[u])
        continue;
      for (int i = 0; i < (int) graph[u].size(); i++) {
        Edge &e = graph[u][i];
        int v = e.to;
        if (e.cap <= e.f) continue;
        int nprio = prio[u] + e.cost + pot[u] - pot[v];
        if (prio[v] > nprio) {
          prio[v] = nprio;
          q.push(((ll) nprio << 32) + v);
          prevnode[v] = u;
          prevedge[v] = i;
          curflow[v] = min(curflow[u], e.cap - e.f);
        }
      }
    }
    if (prio[t] == INF)
      break;
    for (int i = 0; i < n; i++)
      pot[i] += prio[i];
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for (int v = t; v != s; v = prevnode[v]) {
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}

// Usage example

int main() {

	int time;
	cin>>time;
	for(int tt = 1 ; tt <= time ; tt++) {
		CLEAR();
		cin>>n>>m>>s>>t;
		for(int i = 1 ; i <= m ; i++) {
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			//first node , second node , capacity , cost
			addEdge(a, b, c, d);
		}
		cout<<"Test Case "<<tt<<":"<<endl;

	  	pii res = minCostFlow(s, t, INF);
	  	int flow = res.first;
	  	int flowCost = res.second;
	  	cout<<flow<<" "<<flowCost<<endl<<endl;
	}

  
}






