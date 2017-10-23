/*if we want max weight perfect matching then the edges
that are not in the graph should have -INF weight
if we want just max weight matching then the edges
that are not in the graph should have 0 weight
if we want min wieght matching then we negative the edges weight*/
int a[MAX_N][MAX_N];
int ulable[MAX_N], dlable[MAX_N];
int umatch[MAX_N], dmatch[MAX_N];
int umark[MAX_N], dmark[MAX_N];
int n, m;

bool dfs(int k){
    umark[k]=1;
    for(int i=0; i<n; i++) if(dmark[i]==0 && ulable[k]+dlable[i]==a[k][i]){
        dmark[i]=1;
        bool done=0;
        if(dmatch[i]==-1){
            done=1;
        }else{
            if(dfs(dmatch[i]))  done=1;
        }
        if(done){
            umatch[k]=i;
            dmatch[i]=k;
            return 1;
        }
    }
    return 0;
}

void mwmatching(){
    for(int i = 0 ; i < MAX_N ; i++)
        ulable[i] = dlable[i] = 0;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        ulable[i]=max(ulable[i], a[i][j]);
    for(int i = 0 ; i < MAX_N ; i++)
        umatch[i] = dmatch[i] = -1;
    for(int size=0; size<n; ){
        bool done=1;
        while(done){
            done=0;
            for(int i = 0 ; i < MAX_N ; i++)
                umark[i] = dmark[i] = 0;
            for(int i=0; i<n; i++)  if(umark[i]==0 && umatch[i]==-1)
                if(dfs(i)){
                    done=1;
                    size++;
                }
        }
        int eps=(int)(1e9);
        for(int i=0; i<n; i++)  if(umark[i])
        for(int j=0; j<n; j++)  if(!dmark[j])
            eps=min(eps, ulable[i]+dlable[j]-a[i][j]);
        for(int i=0; i<n; i++)
            if(umark[i])    ulable[i]-=eps;
        for(int i=0; i<n; i++)
            if(dmark[i])    dlable[i]+=eps;
    }
}

int main(){

    cin >>n >>m;
    for(int i=0; i<m; i++){
        int x, y, w;
        cin >>x >>y >>w;
        x--;    y--;
        a[x][y]=max(w, a[x][y]);
    }

    mwmatching();

    int ans=0;
    for(int i=0; i<n; i++)
        ans+=a[i][umatch[i]];
    cout <<ans <<endl;

    return 0;
}

