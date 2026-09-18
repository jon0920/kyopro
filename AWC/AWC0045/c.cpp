#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, q;
    cin >> n >> q;
    vector<ll> p(n + 1);

    while(q--){
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        p[l] += c;
        p[r] -= c;
    }

    for(int i = 1; i < n; i++) p[i] += p[i - 1];

    rep(i,n) cout << p[i] << " ";
    cout << endl;

    return 0;
}