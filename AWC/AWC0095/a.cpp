#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> ans(n);
    rep(i,m){
        int p, k;
        ll c;
        cin >> p >> c >> k;
        ans[p - 1] += c;
        rep(j,k){
            int b;
            cin >> b;
            ans[b - 1] -= c / k;
        }
    }

    rep(i,n) cout << ans[i] << endl;
    
    return 0;
}