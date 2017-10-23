//for memory optimization we can find radical(n) primes
//and then use the mark[radical(MAX_N)] for the next primes and so on...
bool mark[MAX_N];
vector<ll>p;

void sieve() {
    mark[1] = true;
    for(ll i = 2 ; i < MAX_N ; i++) {
        if(!mark[i]) {
            p.push_back(i);
            for(ll j = i*i ; j < MAX_N ; j += i)
                mark[j] = true;
        }
    }
}