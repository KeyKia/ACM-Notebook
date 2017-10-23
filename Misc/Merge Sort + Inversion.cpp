
ll n,a[MAX_N],inv[MAX_N];
pair<ll,ll>b[MAX_N],tmp[MAX_N];
//b[i].first = a[i], b[i].second = i
//inv[i] = inversions of index i

void mergeSort(ll left,ll right) {
    if(left == right)
        return;
    ll mid = (left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    ll k = 1,i = left,j = mid+1;
    while(i<=mid && j <= right) {

        if(b[i].first <= b[j].first) {
            inv[b[i].second] += j-(mid+1);
            tmp[k] = b[i];
            i++;
            k++;

        }
        else {
            tmp[k] = b[j];
            k++;
            j++;
        }
    }
    for(int q = i ; q <= mid ; q++,k++) {
        inv[b[q].second] += (right-mid);
        tmp[k] = b[q];
    }
    for(int q = j ; q <= right ; q++,k++)
        tmp[k] = b[q];
    k--;
    for(int q = 1 ; q  <= k ; q++)
        b[left+q-1] = tmp[q];

}
/////////////////////////////////////////
/////////////////////////////////////////
int n,a[MAX_N],fenv[MAX_N];
//if MAX_N is Maximum Number that exist we dont have to make between 1 to  n
// numbers must be between 1 to n

void fen(ll x) {
    while(x<MAX_N)
    {
        fenv[x]++;
        x += x & -x;
    }
}
ll getsum(ll x) {
    ll ret= 0;
    while(x>0)
    {
        ret += fenv[x];
        x -= x & -x;
    }
    return ret;
}

ll inversion() {
    ll ret = 0;
    for (int i=n-1; i>=0; i--) {
        ret += getsum(a[i]-1);
        fen(arr[i]);
    }
 
    return ret;
}
}

