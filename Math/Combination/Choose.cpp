ll C[MAX_N][MAX_N];

void FILL_CHOOSE() {
    for(int i = 0 ; i < MAX_N ; i++)
        C[i][0] = 1;
    for(int i = 1 ; i < MAX_N ; i++)
        C[i][i] = 1;
    for(int i = 1 ; i < MAX_N ; i++)
        for(int j = 1 ; j < i ; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;

}

int nCrModpLucas(int n,int r,int p){
    if(r==0)
        return 1;
    int ni=n%p;
    int ri=r%p;
    return (nCrModpLucas(n/p,r/p,p)*nCrModpLucas(ni,ri,p))%p;
}
