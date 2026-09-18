#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    multiset<ll> a;
    vector<ll> b(m);
    rep(i,n){
        ll x;
        cin >> x;
        a.insert(x);
    }

    rep(i,m) cin >> b[i];
    sort(b.rbegin(), b.rend());

    int cnt = 0;
    for(ll x : b){
        auto it = a.lower_bound(x);
        if(it == a.end()){
            cout << -1 << endl;
            return 0;
        }
        if(*it == x) cnt++;
        a.erase(it);
    }

    cout << cnt << endl;

    return 0;
}