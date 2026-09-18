#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    rep(i,m){
        int k;
        cin >> k;
        ll ans = 0;
        rep(j,k){
            int a;
            cin >> a;
            ans += w[a - 1];
        }
        cout << ans << endl;
    }
    
    return 0;
}