#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> p(n), c(n);
    rep(i,n) cin >> p[i] >> c[i];
    vector<int> u(m), v(m);
    rep(i,m){
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        bool ok = true;
        int sum = 0;
        rep(i,m){
            if((bit >> u[i]) & 1){
                if(!((bit >> v[i]) & 1)) ok = false;
            }
        }
        if(ok){
            rep(i,n){
                if((bit >> i) & 1) sum += p[i] - c[i];
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
    
    return 0;
}