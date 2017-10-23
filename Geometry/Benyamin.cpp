//IN THE NAME OF GOD

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5+10;
const int INF = 1e9;
const long double eps = 1e-8;
const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

bool is_zero(long double x) {
	if(abs(x) <= eps)
		return true;
	return false;
}

struct point {
public:
	long double x, y;
	point() {

	}
	point(long double xx, long double yy) {
		x = xx;
		y = yy;
	}
	
};

long double distance(point me, point other) {
		long double ret = (other.x - me.x)*(other.x - me.x) + (other.y - me.y)*(other.y - me.y);
		return sqrt(ret);
}

struct circle {
public:
	long double r;
	point center;
	circle(long double rr, long double x, long double y) {
		r = rr;
		center.x = x;
		center.y = y;
	}
	long double S() {
		return PI*r*r;
	}
	 long double P() {
		return 2*PI*r;
	}
	/*
	0 = outside of circle
	1 = on the circle 
	2 = inside of circle
	*/
	int is_inside(point other) {
		if(is_zero(distance(center, other)-r))
			return 1;
		if(distance(center, other) <= r) 
			return 2;
		return 0;
	}
	/*
	0 = other is inside this, zero point
	1 = other is tangent inisde of this, one point 
	2 = other is intersect with this, two point
	3 = other is tangent outside of this, one point
	4 = other is outside of this, zero point
	*/
	pair<int, vector<point> > intersect(circle other) {
		vector<point> v;
		long double sumr = other.r + r;
		long double rr = r - other.r;
		long double dis = distance(center, other.center);

		long double a = (r*r - other.r*other.r + dis*dis)/(2*dis);
		long double h = sqrt(r*r-a*a);
		point p2(center.x, center.y);
		p2.x = a*(other.center.x - center.x)/dis;
		p2.y = a*(other.center.y - center.y)/dis;
		
		//cout<<rr<<" "<<dis<<endl;

		if(is_zero(sumr-dis)) {
			v.push_back(p2);
			return make_pair(3, v);
		}
		if(is_zero(rr - dis)) {
			v.push_back(p2);
			return make_pair(1, v);
		}
		if(dis <= rr) 
			return make_pair(0, v);
		if(dis >= sumr)
			return make_pair(4, v);

		
		point p3(p2.x + h*(other.center.y - center.y)/dis, p2.y - h*(other.center.x - center.x)/dis);
		point p4(p2.x - h*(other.center.y - center.y)/dis, p2.y + h*(other.center.x - center.x)/dis);
		v.push_back(p3);
		v.push_back(p4);
		return make_pair(2, v);
	}
};

