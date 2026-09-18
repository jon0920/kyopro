#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> imos(n + 1);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++;
        imos[r]--;
    }
    rep(i,n) imos[i + 1] += imos[i];

    rep(i,n) cout << a[i] * imos[i] << " ";
    cout << endl;

    return 0;
}