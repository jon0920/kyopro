#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

int main(){
    
    int n;
    cin >> n;
    set<ll> st = {INF, -INF};
    rep(i,n){
        ll a;
        cin >> a;
        st.insert(a);
    }

    ll cur = 0;
    ll ans = 0;
    while(st.size() > 2){
        auto it = st.lower_bound(cur);
        auto pre = prev(it);
        if(abs(cur - *it) >= abs(cur - *pre)){
            ans += abs(cur - *pre);
            cur = *pre;
            st.erase(pre);
        } else {
            ans += abs(cur - *it);
            cur = *it;
            st.erase(it);
        }
    }

    cout << ans << endl;
    
    return 0;
}