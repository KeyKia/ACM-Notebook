//SEGMENT 2D FOR MAX_MIN A RECTANGLE AND CHANGE A NUMBER 
const int MAX_N = 500+10;
const int INF = 1e9;

int n,a[MAX_N][MAX_N],m;
pair<int,int> seg[16*MAX_N*MAX_N];

//X az from tx to dx 
//Y az from ly to ry
//we want to change (x,y) to new_num
pair<int,int> change(int node_num,int tx,int dx,int ly,int ry,int x,int y,int new_num) {
	if(tx > dx || ly > ry)
		return make_pair(0,INF);
	if(x < tx || x > dx || y < ly || y > ry) 
		return seg[node_num];
	if(tx == dx && tx == x && ly == ry && ly == y) 
		return seg[node_num] = make_pair(new_num,new_num);
	int midx = (tx+dx)/2;
	int midy = (ly+ry)/2;
	pair<int,int>A = change(4*node_num-2,tx,midx,ly,midy,x,y,new_num);
	pair<int,int>B = change(4*node_num-1,tx,midx,midy+1,ry,x,y,new_num);
	pair<int,int>C = change(4*node_num,midx+1,dx,ly,midy,x,y,new_num);
	pair<int,int>D = change(4*node_num+1,midx+1,dx,midy+1,ry,x,y,new_num);
	return seg[node_num] = make_pair(max(max(A.first,B.first),max(C.first,D.first)),min(min(A.second,B.second),min(C.second,D.second)));
}
//X az from tx to dx 
//Y az from ly to ry
//we looking for X from a to b
//and Y from c to d
pair<int,int> max_min(int node_num,int tx,int dx,int ly,int ry,int a,int b,int c,int d) {
	if(a > dx || b < tx || c > ry || d < ly || tx > dx || ly > ry)
		return make_pair(0,INF);
	a = max(a,tx);
	b = min(b,dx);
	c = max(c,ly);
	d = min(d,ry);
	if(tx == a && dx == b && ly == c && ry == d)
		return seg[node_num];

	int midx = (tx+dx)/2;
	int midy = (ly+ry)/2;
	pair<int,int>A = max_min(4*node_num-2,tx,midx,ly,midy,a,b,c,d);
	pair<int,int>B = max_min(4*node_num-1,tx,midx,midy+1,ry,a,b,c,d);
	pair<int,int>C = max_min(4*node_num,midx+1,dx,ly,midy,a,b,c,d);
	pair<int,int>D = max_min(4*node_num+1,midx+1,dx,midy+1,ry,a,b,c,d);
	return make_pair(max(max(A.first,B.first),max(C.first,D.first)),min(min(A.second,B.second),min(C.second,D.second)));
}

