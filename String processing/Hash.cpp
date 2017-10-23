
string s;
ull h[MAX_N],po[MAX_N];
//one base
ull gethash(int i,int j) {
    i--;
    return h[j] - h[i] * po[j-i];
}
void HASH() {
    po[0]=1;
    for(int i=1;i<MAX_N;i++)
		po[i]=po[i-1]*31;
    for(int i=1;i<=s.size();i++)
		h[i]= h[i-1]*31 + (s[i-1] - 'a'+1);
}