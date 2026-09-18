#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];

    rep(i,m){
        int k;
        cin >> k;
        ll sum = 0;
        rep(j,k){
            int c;
            cin >> c;
            c--;
            sum += (p[c] - q[c]);
        }
        cout << sum << endl;
    }
    
    return 0;
}