ll changeBaseFromBaseToTen(vector<int> num,int base) {
    ll co = 1;
    ll ret = 0;
    for(int i = num.size() -1 ; i >= 0 ; i--) {
        ret += co*num[i];
        co *= base;
    }
    return ret;
}
vector<int> changeBaseFromTenToBase(ll num,int base) {
    vector<int>ret;
    while(num != 0) {
        ret.push_back(num%base);
        num /= base;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}


