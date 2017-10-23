ll POW(ll a, ll x) {
    if(x == 1) return a;
    if(x%2 == 0)
        return POW((a*a)%MOD, x/2);
    else
        return (a*(POW((a*a)%MOD, x/2)))%MOD;
}
