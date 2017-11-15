#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+3;
struct Point { int x; int y; };
Point p[MAXN]; //Points to be processed
vector<Point> S; //Contains the convex hull

// ------------------------------- General ---------------------------- //

double signed_triangle_area (Point a, Point b, Point c) {
	return( (a.x*b.y - a.y*b.x + a.y*c.x
	- a.x*c.y + b.x*c.y - c.x*b.y) / 2.0 );
}

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock(1) or counterclockwise(2)
}

// ------------------------------- Segment Intersection ---------------------------- //

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool segmentIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4)
        return true;
     // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}

// ------------------------------- Convex Hull ---------------------------- //

//Returns the square of distance
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

bool cmp (Point p1, Point p2) {
	int o = orientation(p1, p[0], p2);
	if (o==0) return (distSq(p[0], p1) <= distSq(p[0], p2));
	return (o==1);
}

void convexHull (int n) {
	// Find the bottommost-leftmost point
   int ymn = p[0].y, mn = 0;
   for (int i = 1; i < n; i++) {
     int y = p[i].y;
     if ((y < ymn) || (ymn == y && p[i].x < p[mn].x))
        ymn = p[i].y, mn = i;
   }
   swap(p[0], p[mn]);
   sort(&p[1], p+n, cmp);
   int m=1; //Removing collinears and same points
   for (int i=1; i<n; i++) {
       while (i < n-1 && orientation(p[0], p[i], p[i+1]) == 0)
          i++;
       p[m] = p[i]; m++;
   }
   if (m<3) return; // Go for the convex hull
   S.push_back(p[0]); S.push_back(p[1]); S.push_back(p[2]);
   for (int i = 3; i < m; i++) {
      // Keep removing top while the turn is not ccw
      while (orientation(S[S.size()-2], S[S.size()-1], p[i]) != 2)
         S.pop_back();
      S.push_back(p[i]);
   }
}