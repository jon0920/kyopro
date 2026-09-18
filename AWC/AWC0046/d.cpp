#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    vector<int> v;
    rep(i,n){
        v.push_back(d[i]);
        v.push_back(d[i] - k + 1);
    }

    sort(v.begin(), v.end());
    int mid = v[n];
    
    ll ans = 0;
    rep(i,n){
        if(d[i] < mid) ans += mid - d[i];
        if(mid + k - 1 < d[i]) ans += d[i] - (mid + k - 1);
    }

    cout << ans << endl;

    return 0;
}