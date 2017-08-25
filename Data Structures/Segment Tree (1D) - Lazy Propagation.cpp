/* In the Name of God */

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <fstream>
#include <queue>
#include <cstring>
#include <iomanip>
#include <stack>
#include <map>
#include <cstdlib>
#include <deque> 

using namespace std;

typedef long long ll ;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second

const int N=100000+5;
ll t, n, c, q, l, r, w,  val[4*N], flg[4*N];

inline void shift ( ll x, ll xl, ll xr ) {
  ll mid=(xl+xr)>>1;
  flg[2*x+1]+=flg[x];
  flg[2*x+2]+=flg[x];
  val[2*x+1]+=(mid-xl)*flg[x];
  val[2*x+2]+=(xr-mid)*flg[x];
  flg[x]=0;
}

inline void change ( ll x, ll xl, ll xr, ll ql, ll qr, ll qv ) {
  if (xr<=ql || qr<=xl) return;
  if (ql<=xl && xr<=qr) {
    flg[x]+=qv;
    val[x]+=(xr-xl)*qv;
    return;
  }
  if (flg[x]!=0) shift(x,xl,xr);
  ll mid=(xl+xr)>>1;
  change(2*x+1,xl,mid,ql,qr,qv);
  change(2*x+2,mid,xr,ql,qr,qv);
  val[x]=val[2*x+1]+val[2*x+2];
}

inline ll ask ( ll x, ll xl, ll xr, ll ql, ll qr ) {
  if (xr<=ql || qr<=xl) return 0;
  if (ql<=xl && xr<=qr) return val[x];
  if (flg[x]!=0) shift(x,xl,xr);
  ll mid=(xl+xr)>>1;
  return ask(2*x+1,xl,mid,ql,qr) + ask(2*x+2,mid,xr,ql,qr);
}

int main () {
  scanf("%lld", &t);
  while (t--) {
    memset(val,0,sizeof val);
    memset(flg,0,sizeof flg);
    scanf("%lld%lld", &n, &c);
    while (c--) {
      scanf("%lld", &q);
      if (q==0){
	scanf("%lld%lld%lld", &l, &r, &w);
	l--;
	change(0,0,n,l,r,w);
      }      
      else {
	scanf("%lld%lld", &l, &r);
	l--;
	printf("%lld\n", ask(0,0,n,l,r));
      }
    }
  }

  return 0;
}




