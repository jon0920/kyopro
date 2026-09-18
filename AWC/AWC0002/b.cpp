#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    set<ll> st; 
    rep(i,n) cin >> a[i];
    rep(i,m){
        ll b;
        cin >> b;
        b--;
        st.insert(b);
    }

    ll ans = 0, cnt = 0;
    rep(i,n){
        if(st.count(i)){
            if(a[i] < k){
                ans += a[i];
                cnt++;
            }
        }
    }

    cout << cnt << " " << ans << endl;

    return 0;
}