#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

//intervalset
int main(){
    
    ll n, q;
    cin >> n >> q;
    set<pair<ll,ll>> st;
    st.insert({-INF, -INF});
    st.insert({INF, INF});

    ll res = n;
    while(q--){
        ll l, r;
        cin >> l >> r;
        l--;

        auto it = st.lower_bound({l, -INF});
        auto pre = prev(it);

        if(pre->second >= l){
            res += pre->second - pre->first;
            l = pre->first;
            r = max(r, pre->second);
            st.erase(pre);
        }

        while(it->first <= r){
            res += it->second - it->first;
            r = max(r, it->second);
            it = st.erase(it);
        }

        st.insert({l, r});
        res -= r - l;

        cout << res << "\n";
    }

    return 0;
}