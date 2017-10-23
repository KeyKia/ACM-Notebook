ll gcd(ll x,ll y) {
    if(y > x)
        swap(x,y);
    if(y == 0)
        return x;
    return gcd(y,x%y);
}

ll lcm(ll x, ll y) {
    return a*(b/gcd(x,y));
}
