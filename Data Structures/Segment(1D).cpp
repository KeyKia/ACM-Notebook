//SEGMENT 1D for sum and add x to interval

const int MAX_N = 2*(1e5+10);

int n,seg[4*MAX_N],a[MAX_N],flag[4*MAX_N];


int make(int node_num,int l,int r) {
	if(l == r) 
		return seg[node_num] = a[l];
	int mid = (l+r)/2;
	return seg[node_num] = make(2*node_num,l,mid)+make(2*node_num+1,mid+1,r);
}
//were in node_num that is between [l,r] and we want to find sum of [low,high]
int sum(int node_num,int l,int r,int low,int high) {
	if(high < l || low > r)
		return 0;
	low = max(low,l);
	high = min(high,r);
	if(l == low && r == high)
		return seg[node_num];
	int mid = (l+r)/2;
	return sum(2*node_num,l,mid,low,high)+sum(2*node_num+1,mid+1,r,low,high);
}
//set node ind to new_num
int change(int node_num,int l,int r,int ind,int new_num) {
	if(ind > r || ind < l)
		return seg[node_num];
	if(l == r && l == ind) 
		return seg[node_num] = new_num;
	int mid = (l+r)/2;
	return seg[node_num] = change(2*node_num,l,mid,ind,new_num) + change(2*node_num+1,mid+1,r,ind,new_num);
}




int sum(int node_num,int l,int r,int low,int high) {
	if(high < l || low > r)
		return 0;
	low = max(low,l);
	high = min(high,r);
	if(l == low && r == high)
		return seg[node_num];
	int mid = (l+r)/2;
	return (flag[node_num] * (high-low+1))+(sum(2*node_num,l,mid,low,high)+sum(2*node_num+1,mid+1,r,low,high));
}
//add  x to all numbers in [low,high]
int change(int node_num,int l,int r,int low,int high,int x) {
	if(high < l || low > r) 
		return seg[node_num];
	low = max(low,l);
	high = min(high,r);
	if(l == low && r == high) {
		flag[node_num] += x;
		return seg[node_num] = seg[node_num] + ((r-l)+1)*x;
	}
	int mid = (l+r)/2;
	return seg[node_num] = change(2*node_num,l,mid,low,high,x)+change(2*node_num+1,mid+1,r,low,high,x);
}


