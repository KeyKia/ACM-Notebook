ll modulo(ll x, ll y, ll Mod){
	ll ret=1;
	for(; y!=0; y/=2){
		if(y%2)	ret=(ret*x)%Mod;
		x=(x*x)%Mod;
	}
	return ret;
}
bool Miller(ll p,int iteration){
	if(p<2)		return 0;
	if(p==2)	return 1;
	if(p%2==0)	return 0;
	ll s=p-1;
	while(s%2==0)	s/=2;
	for(int i=0; i<iteration; i++){
		ll a=rand()%(p-1)+1, temp=s;
		ll mod=modulo(a, temp, p);
		while(temp!=p-1 && mod!=1 && mod!=p-1){
			mod=(mod*mod)%p;
			temp*=2;
		}
		if(mod!=p-1 && temp%2==0)
			return 0;
	}
	return 1;
}