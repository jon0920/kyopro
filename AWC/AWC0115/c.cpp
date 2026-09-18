#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> v;
    rep(i,n){
        ll h;
        cin >> h;
        if(h <= 0) v.push_back(-h);
    }
    sort(v.begin(), v.end());

    int m = v.size();
    rep(i,m){
        int cnt = (v[i] + p) / p;
        if(cnt > k){
            cout << m - i << endl;
            return 0;
        }
        k -= cnt;
    }

    cout << 0 << endl;
    
    return 0;
}