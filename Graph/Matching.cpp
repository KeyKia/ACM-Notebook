
//1 to n1  first independent part
//n1+1 to n1+n2 second independent part
int n1,n2,match[MAX_N];
bool mark[MAX_N];
vector<int>v[MAX_N];

bool dfs(int u) {
    if(mark[u])
        return false;
    mark[u] = true;
    for(int i = 0 ; i < v[u].size() ; i++) {
        int w = v[u][i];
        if(match[w] == -1 || dfs(match[w])) {
            match[w] = u;
            match[u] = w;
            return true;
        }
    }
    return false;
}

void optimize() {
    for(int i = 1 ; i <= n1 ; i++) {
        for(int j = 0 ; j < v[i].size() ; j++) {
            if(match[v[i][j]] == -1) {
                match[i] = v[i][j];
                match[v[i][j]] = i;
                break;
            }
        }
    }
}

void MATCH() {
    for(int i = 1 ; i <= n1+n2 ; i++) match[i] = -1;
    optimize();
    for(int i = 1 ; i <= n1 ; i++) {
        if(match[i] != -1)
            continue;
        for(int j = 0 ; j < MAX_N ; j++)
            mark[j] = false;
        dfs(i);
    }
}


