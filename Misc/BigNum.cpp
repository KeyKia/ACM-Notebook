#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int M=1000+10;

struct Int{
	int a[M], s;

	Int(int k=0){
		memset(a, 0, sizeof a);
		s=(k==0?0:-1);
		for(; k!=0; k/=10)	a[++s]=k%10;
		while(s>0 && a[s]==0)	s--;
	}
	Int(string t){
		memset(a, 0, sizeof a);
		s=(int)t.size()-1;
		for(int i=0; i<=s; i++)	a[i]=(t[s-i]-'0');
		while(s>0 && a[s]==0)	s--;
	}

	inline friend istream& operator >> (istream& in, Int& N) {
		string t;
		in >>t;
		memset(N.a, 0, sizeof N.a);
		N.s=(int)t.size()-1;
		for(int i=0; i<=N.s; i++)	N.a[i]=(t[N.s-i]-'0');
		while(N.s>0 && N.a[N.s]==0)	N.s--;
		return in;
	}
	inline friend ostream& operator << (ostream& out, const Int& N) {
		for(int i=N.s; i>=0; i--)
			out <<N.a[i];
		return out;
	}
	
	bool operator < (const Int& N) const {
		if(s!=N.s)	return s<N.s;
		for(int i=s; i>=0; i--)
			if(a[i]!=N.a[i])	return a[i]<N.a[i];
		return 0;
	}
	bool operator <= (const Int& N) const {
		if(s!=N.s)	return s<N.s;
		for(int i=s; i>=0; i--)
			if(a[i]!=N.a[i])	return a[i]<N.a[i];
		return 1;
	}
	bool operator == (const Int& N) const {
		if(s!=N.s)	return 0;
		for(int i=s; i>=0; i--)
			if(a[i]!=N.a[i])	return 0;
		return 1;
	}
	Int operator + (const Int& N) const {
		Int ret;
		ret.s=max(N.s, s)+5;
		for(int i=0; i<=ret.s; i++)	ret.a[i]=a[i]+N.a[i];
		for(int i=0; i<=ret.s; i++){
			ret.a[i+1]+=ret.a[i]/10;	ret.a[i]%=10;
		}
		while(ret.s>0 && ret.a[ret.s]==0)	ret.s--;
		return ret;
	}
	Int operator - (const Int& N) const {
		Int ret;
		ret.s=s+5;
		for(int i=0; i<=ret.s; i++)	ret.a[i]=a[i]-N.a[i];
		for(int i=0; i<=ret.s; i++)
			while(ret.a[i]<0){
				ret.a[i]+=10;
				ret.a[i+1]--;
			}
		while(ret.s>0 && ret.a[ret.s]==0)	ret.s--;
		return ret;
	}
	Int operator * (const Int& N) const {
		Int ret;
		ret.s=s+N.s+10;
		for(int i=0; i<=s; i++)
		for(int j=0; j<=N.s; j++)
			ret.a[i+j]+=a[i]*N.a[j];
		for(int i=0; i<=ret.s; i++){
			ret.a[i+1]+=ret.a[i]/10;	ret.a[i]%=10;
		}
		while(ret.s>0 && ret.a[ret.s]==0)	ret.s--;
		return ret;
	}
	Int operator / (const Int& N) const {
		Int ret, r;
		ret.s=s+5;
		for(int i=s; i>=0; i--){
			r=r*Int(10)+Int(a[i]);
			while(N<=r){
				r=r-N;
				ret.a[i]++;
			}
		}
		while(ret.s>0 && ret.a[ret.s]==0)	ret.s--;
		return ret;
	}
	Int operator % (const Int& N) const {
		Int r;
		for(int i=s; i>=0; i--){
			r=r*Int(10)+Int(a[i]);
			while(N<=r)
				r=r-N;
		}
		return r;
	}
	Int operator ^ (const Int& M) const {
		Int ret=Int(1);
		Int po=*this;
		Int N=M;
		while(!(N.s==0 && N.a[0]==0)){
			if(N.a[0]%2==1)
				ret=ret*po;
			N=N/Int(2);
			po=po*po;
		}
		return ret;
	}
};

int main(){
	
	int x, y;
	cin >>x >>y;
	Int X(x), Y(y);
	int ret=1;
	for(int i=1; i<=y; i++)	ret*=x;
	Int RET=X^Y;
	cout <<X+Y <<" " <<X-Y <<" " <<X*Y <<" " <<X/Y <<" " <<X%Y <<" " <<RET <<endl;
	cout <<x+y <<" " <<x-y <<" " <<x*y <<" " <<x/y <<" " <<x%y <<" " <<ret <<endl;
}

