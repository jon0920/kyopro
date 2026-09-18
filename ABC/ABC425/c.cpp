#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n * 2);
    rep(i,2) rep(j,n) b[i * n + j] = a[j];
    vector<ll> sum(n * 2 + 1);
    rep(i,n * 2) sum[i + 1] = sum[i] + b[i];
    
    int movecount = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int c;
            cin >> c;
            movecount = (movecount + c) % n;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            cout << sum[r + movecount] - sum[l + movecount] << endl; 
        }
    }
    
    return 0;
}