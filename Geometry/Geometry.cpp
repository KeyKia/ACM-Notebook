(PI/3) * (H *H) * (3*R-H) 
volume of part of sphere H is height fromt the buttom 
R is the radius of sphere
-------------------------
counter clockwise rotation : 

cost  -sint  *  x   = x'
sint   cost  * y   = y'


struct CMP{
	bool operator() (const pii& x, const pii& y) const{
		if(x.first==y.first){
			return (x.second>y.second);
		}
		return (x.first>y.first);
	}
};
struct Point{
	double x,y;
	Point(double xx=0.0,double yy=0.0){
		x=xx;
		y=yy;
	}
	bool operator <(const Point &p) const {
		return x<p.x || (x==p.x && y<p.y);
	}
};
bool isZero(double x){
	return ((x<1e-6) && (x>-1e-6));
}
// cosinos
double dot(Point a,Point b,Point c,Point d){
	b.x-=a.x;
	b.y-=a.y;
	d.x-=c.x;
	d.y-=c.y;
	double ret = (b.x*d.x)+(b.y*d.y);
	return ret;
}
// sinos
double cross(Point a,Point b,Point c,Point d){
	b.x-=a.x;
	b.y-=a.y;
	d.x-=c.x;
	d.y-=c.y;
	double ret = (b.x*d.y)-(b.y*d.x);
	return ret;
}
pair <double,double> lineLineInt;
bool lineLineIntersection(double a1,double b1,double c1,double a2,double b2,double c2){
	double det = a1*b2-a2*b1;
	if(isZero(det)){
		return 0;
	}else{
		double x = (b2*c1 - b1*c2)/det;
		double y = (a1*c2 - a2*c1)/det;
		lineLineInt.first=x;
		lineLineInt.second=y;
		return 1;
	}
}
double dis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double linePointDis(Point a,Point b,Point c){
	return abs((cross(a,b,a,c)/dis(a,b)));
}
double area(vector <Point> p){
	double ret=cross(p[0],p[1],p[0],p[2]);
	for(int i=3;i<p.size();i++){
		ret = ret + cross(p[0],p[i-1],p[0],p[i]);
	}
	return abs(ret);
}
/////////////////////////////////////////////////////////////////////////
bool cmp(Point x,Point y){
	if(isZero(x.x-y.x)){
		return (x.y < y.y);
	}else{
		return (x.x < y.x);
	}
}
vector <Point> convexHull(vector <Point> p){
	sort(p.begin(),p.end(),cmp);
	vector <Point> u,l;
	u.clear();
	l.clear();
	
	for(int i=0;i<p.size();i++){
		while(l.size()>=2){
			if(cross(l[l.size()-1] ,l[l.size()-2] , l[l.size()-1] , p[i]) > 1e-6){
				l.pop_back();
			}else{
				break;
			}
		}
		l.push_back(p[i]);
	}
	l.pop_back();
	
	for(int i=p.size()-1;i>=0;i--){
		while(u.size()>=2){
			if(cross(u[u.size()-1] ,u[u.size()-2] , u[u.size()-1] , p[i]) > 1e-6){
				u.pop_back();
			}else{
				break;
			}
		}
		u.push_back(p[i]);
	}
	u.pop_back();
	
	vector <Point> ret;
	ret.clear();
	for(int i=0;i<l.size();i++){
		ret.push_back(l[i]);
	}
	for(int i=0;i<u.size();i++){
		ret.push_back(u[i]);
	}
	return ret;
}
////////////////////////////////////////////////////////////////////////
//Point in polygon
//complex
bool is_strictly_in(vector<point>& V, point p){
	double total=0.0;
	for(int i=0; i<(int)V.size(); i++){
		total+=arg((V[i]-p)/(V[(i+1)%(int)V.size()]-p));
	}
	if(total<0) total*=-1.0;
	return total>=3.0;
}
/////////////////////////////////////////////////////////////////////////
const double inf = 1e10;
bool cmp1(Point x,Point y){
	if(isZero(x.y-y.y)){
		return (x.x < y.x);
	}else{
		return (x.y < y.y);
	}
}
double minDis(vector <Point> &p,int l,int r){
	if(l==r){
		return inf;
	}
	if(l==r-1){
		return dis(p[l],p[r]);
	}
	int mid=(l+r)/2;
	double ans = min(minDis(p,l,mid),minDis(p,mid+1,r));
	vector <Point> k;
	k.clear();
	for(int i=l;i<=r;i++){
		if(p[mid].x-p[i].x < ans+1e-6 && p[mid].x-p[i].x > -ans-1e-6){
			k.push_back(p[i]);
		}
	}
	sort(k.begin(),k.end(),cmp1);
	const int len=7;
	for(int i=0;i<k.size();i++){
		for(int j=i+1;j<k.size() && j<i+len ; j++){
			ans = min(ans,dis(k[i],k[j]));
		}
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector <Point> a;
	for(int i=0;i<n;i++){
		double x,y;
		cin>>x>>y;
		Point p(x,y);
		a.push_back(p);
	}
	sort(a.begin(),a.end(),cmp);
	cout<<minDis(a,0,n-1)<<endl;
	return 0;
	a=convexHull(a);
	for(int i=0;i<a.size();i++){
		cout<<a[i].x<<" "<<a[i].y<<endl;
	}
}
///////////////////////NEW/////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

const int MAX_N=1000+10;
const double eps=1e-6;
typedef complex<double> point;
//Ax+By=C
struct line{
	double A, B, C;
	line(double A=0.0, double B=0.0, double C=0.0): A(A), B(B), C(C){}
};

bool is_zero(double d){
	return -eps<=d && d<=eps;
}

//product of q_p1 p1_p2
double dot(point q, point p1, point p2){
	p2-=p1;
	p1-=q;
	return p1.real()*p2.real()+p1.imag()*p2.imag();
}
//product of q_p1 q_p2
double cross(
	point q, point p1, point p2){
	p1-=q;	p2-=q;
	return p1.real()*p2.imag()-p1.imag()*p2.real();
}
double Distance(const point& p, const point& q){
	return sqrt((p.real()-q.real())*(p.real()-q.real())+(p.imag()-q.imag())*(p.imag()-q.imag()));
}
//Distance from P1_P2 to Q
//if issegment is true P1_P2 is segment
double LinePointDis(point p1, point p2, point q, int isSegment){
	double ret=cross(p1,p2,q)/Distance(p1,p2);
	if(isSegment){
		if(dot(p1,p2,q)>0)	return Distance(p2,q);
		if(dot(p2,p1,q)>0)	return Distance(p1,q);
	}
	if(ret<0)	ret*=-1;
	return ret;
}

line point_to_line(const point& p1, const point& p2){
	line ret;
	ret.A=p2.imag()-p1.imag();
	ret.B=p1.real()-p2.real();
	ret.C=ret.A*p1.real()+ret.B*p1.imag();
	return ret;
}
void line_to_point(const line& l, point& p1, point& p2){
	if(is_zero(l.A)){
		p1=point(l.C/l.B, 0.0);
		p2=point(l.C/l.B, 1.0);
	}else{
		p1=point((l.C-l.B*0.0)/l.A, 0.0);
		p2=point((l.C-l.B*1.0)/l.A, 1.0);
	}
}

bool line_line_inter(line l1, line l2, point& p){
	double det=l1.A*l2.B-l2.A*l1.B;
	if(is_zero(det)){
		return 0;
	}else{
		p=point( (l2.B*l1.C-l1.B*l2.C)/det, (l1.A*l2.C-l2.A*l1.C)/det );
		return 1;
	}
}
bool seg_seg_inter(const point& p1, const point& p2, const point& q1, const point& q2, point& p){
	line l1=point_to_line(p1, p2);
	line l2=point_to_line(q1, q2);
	double det=l1.A*l2.B-l2.A*l1.B;
	if(is_zero(det)){
		return 0;
	}else{
		p=point( (l2.B*l1.C-l1.B*l2.C)/det, (l1.A*l2.C-l2.A*l1.C)/det );
		if(p.real()>=max(p1.real(), p2.real())+eps)	return 0;
		if(p.real()<=min(p1.real(), p2.real())-eps)	return 0;
		if(p.real()>=max(q1.real(), q2.real())+eps)	return 0;
		if(p.real()<=min(q1.real(), q2.real())-eps)	return 0;
		return 1;
	}
}

bool find_circle(point p1, point p2, point p3, point& o, double& r){
	line l1=point_to_line(p1, p2);
	swap(l1.A, l1.B);
	l1.A*=-1.0;
	l1.C=(l1.A*((p1.real()+p2.real())/2.0)+l1.B*((p1.imag()+p2.imag())/2.0));
	
	line l2=point_to_line(p1, p3);
	swap(l2.A, l2.B);
	l2.A*=-1.0;
	l2.C=(l2.A*((p1.real()+p3.real())/2.0)+l2.B*((p1.imag()+p3.imag())/2.0));

	if(!line_line_inter(l1, l2, o))	return 0;
	r=Distance(o, p1);
	return 1;
}
vector<point> circle_circle_inter(point o1, double r1, point o2, double r2){
	vector<point> ret;
	double Dis=Distance(o1,o2);
	if(Dis>=r1+r2+eps || Dis<=max(r1,r2)-min(r1,r2)-eps)
		return ret;
	o2-=o1;
	r1/=abs(o2);
	r2/=abs(o2);
	double x=(1.0+r1*r1-r2*r2)/2.0;
	double y=sqrt(max(0.0, r1*r1-x*x));
	ret.push_back(point(x,y));
	if(!is_zero(y))ret.push_back(point(x,-y));
	for(int i=0; i<(int)ret.size(); i++){
		ret[i]*=o2;
		ret[i]+=o1;
	}
	return ret;
}
vector<point> line_circle_inter(point p1, point p2, point o, double r, bool isSegment){
	vector<point> ret;
	double Dis=LinePointDis(p1,p2,o,0);
	if(Dis>=r+eps)	return ret;
	
	p1-=o;	p2-=o;
	line l1=point_to_line(p1,p2);
	line l2(-l1.B, l1.A, 0.0);
	point p;
	line_line_inter(l1,l2,p);
	if(is_zero(abs(p))){
		point ans1=p1/abs(p1)*r;
		point ans2=-ans1;
		ret.push_back(ans1+o);
		ret.push_back(ans2+o);
	}else{
		r/=abs(p);
		double x=1.0;
		double y=sqrt(max(0.0, r*r-1.0));
		ret.push_back(point(x,y)*p+o);
		ret.push_back(point(x,-y)*p+o);
	}
	if(is_zero(abs(ret[0]-ret[1])))
		ret.pop_back();
	if(isSegment){
		p1+=o;	p2+=o;
		vector<point> ans;
		for(int i=0; i<(int)ret.size(); i++){
			if(ret[i].real()>=min(p1.real(),p2.real())-eps && ret[i].real()<=max(p1.real(),p2.real())+eps
			&& ret[i].imag()>=min(p1.imag(),p2.imag())-eps && ret[i].imag()<=max(p1.imag(),p2.imag())+eps)
				ans.push_back(ret[i]);
		}
		return ans;
	}else{
		return ret;
	}
}

int main(){
			
	return 0;
}


