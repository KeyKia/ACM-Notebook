/* if the odd degree vertex is 2 or all degrees are even
   a b m[make_pair(a,b)]++ , m[make_pair(b,a)]++;*/
int n,mm;
vector<int>v[MAX_N];
vector<int>ans;
map<pair<int,int>,int> m;
void Euler(int u) {
    for(int i = 0 ; i < v[u].size() ; i++) {
        int d = v[u][i];
        if(m[make_pair(u,d)] > 0) {
            m[make_pair(u,d)]--;
            m[make_pair(d,u)]--;
            Euler(d);
        }
    }
    ans.push_back(u);
}
