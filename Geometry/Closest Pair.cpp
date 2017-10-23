#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef long long ll;


const int MAX_N = 1e6+10;
const ll INF = 1e18;

struct point {
	ll x,y;
};

int t,n;
point p[MAX_N],p1[MAX_N];
vector<point>v;

bool cmp(point a,point b) {
	if(a.x < b.x)
		return true;
	if(a.x > b.x)
		return false;
	return a.y <= b.y;
}

bool cmp1(point a,point b) {
	if(a.y < b.y)
		return true;
	if(a.y > b.y)
		return false;
	return a.x <= b.x;
}

ll dis(point a,point b) {
	return (a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x);
}

pair<point,point>strip_closest() {
	ll MIN = INF;
	point a,b;
	
	for(int i = 0 ; i < v.size() ; i++) {
		for(int j = i+1 ; j <= min(i+7,int(v.size())-1) ; j++) {
			if(dis(v[i],v[j]) < MIN) {
				MIN = dis(v[i],v[j]);
				a = v[i];
				b = v[j];
			}
		}
	}
	return make_pair(a,b);
}

pair<point,point> closest_pair(int l,int r) {
	if(l == r) {
		return make_pair(p[1],p[2]);
	}
	if(l == r-1) 
		return make_pair(p[l],p[r]);
	int mid = (l+r)/2;
	pair<point,point>ret;
	pair<point,point>a = closest_pair(l,mid);
	pair<point,point>b = closest_pair(mid+1,r);
	ll d;
	if(dis(a.first,a.second) < dis(b.first,b.second)) {
		ret = a;
		d = dis(a.first,a.second);
	}
	else {
		ret = b;
		d = dis(b.first,b.second);
	}
	v.clear();
	for(int i = l ; i <= r ; i++) 
		if(abs(p1[i].x -p1[mid].x) <= d) 
			v.push_back(p1[i]);

	pair<point,point>c = strip_closest();
	if(dis(c.first,c.second) < dis(ret.first,ret.second)) 
		ret = c;
	return ret;

} 

int main() {
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++) {
		scanf("%lld %lld",&p[i].x,&p[i].y);
		p1[i] = p[i];
	}
	sort(p+1,p+n+1,cmp);
	sort(p1+1,p1+n+1,cmp1);
	pair<point,point> ans = closest_pair(1,n);

	


	
}