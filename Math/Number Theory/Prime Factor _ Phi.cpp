//remember to call sieve before
vector<pair<ll,ll> > primeFactor(ll num) {
    vector<pair<ll,ll> >ret;
    for(int i = 0 ; i < p.size() && p[i]<= sqrt(num)+1 ; i++) {
        ll t = 0;
        while(num % p[i] == 0) {
            t++;
            num /= p[i];
        }
        if(t != 0)
            ret.push_back(make_pair(p[i],t));
    }
    if(num != 1)
        ret.push_back(make_pair(num,1));
    return ret;
}

//attention to num = 1 in some case it should return 1
ll phi(ll num) {
    if(num == 1)
        return 0;
    vector<pair<ll,ll> >tmp = primeFactor(num);
    ll ret = num;
    for(int i = 0 ; i < tmp.size() ; i++) {
        ll f = tmp[i].first;
        ret *= f-1;
        ret /= f;
    }
    return ret;
}
