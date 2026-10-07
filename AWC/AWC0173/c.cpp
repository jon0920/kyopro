#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k, m, l;
    cin >> n >> k >> m >> l;
    vector<ll> d(m);
    rep(i,m) cin >> d[i];

    cout << n * l << endl;
    
    return 0;
}