ll x,y,d;
/*
    check for a == 0 && b == 0
    the answer is less for a and more for b
    d = gcd(a,b)
    a*x + b*y = d extendedEuclid counts this x and y
    a*x + b*y = c
    c % d should be 0
    two side of equation * c/d
    answers of X = x+(b/d)*n
    answers of Y = y-(a/d)*n
    n is a integer
    if(n >= a)
        then we should count n >= ceil(a);
        for floor dont make int use floor
*/
void extendedEuclid(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int inv(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
       return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}


 
// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  ..................
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
int chinese_remainder(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
 
    int result = 0;
 
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    return result % prod;
}