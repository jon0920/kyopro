#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    multiset<ll> st;
    rep(i,n){
        ll a;
        cin >> a;
        st.insert(a);
    }

    while(q--){
        ll t, x, r;
        cin >> t >> x >> r;
        if(r == 1) continue;
        
        if(t == 1){
            st.erase(prev(st.end()));
            st.insert(x);
        } else {
            st.erase(st.begin());
            st.insert(x);
        }
    }

    ll ans = 0;
    for(ll x : st){
        ans += x;
    }

    cout << ans << endl;
    
    return 0;
}