#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll x : a) pq.push(x);
    set<ll> st;
    while(st.size() < k){
        ll x = pq.top(); pq.pop();
        if(st.count(x)) continue;
        st.insert(x);

        for(ll y : a) pq.push(x + y);
    }

    cout << *st.rbegin() << endl;
    
    return 0;
}