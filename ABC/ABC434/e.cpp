#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n;
    cin >> n;
    vector<ll> x(n), r(n);
    rep(i,n) cin >> x[i] >> r[i];
    unordered_set<ll> st;
    st.reserve(4 * n);
    rep(i,n){
        st.insert(x[i] - r[i]);
        st.insert(x[i] + r[i]);
    }
    cout << st.size() << endl;
    
    return 0;
}