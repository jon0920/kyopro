#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, s, lim;
    cin >> n >> s >> lim;
    s--;
    vector<ll> a(n - 1);
    rep(i,n - 1) cin >> a[i];

    vector<ll> L = {0}, R = {0};
    for(int i = s; i < n - 1; i++){
        R.push_back(R.back() + a[i]);
    }
    for(int i = s - 1; i >= 0; i--){
        L.push_back(L.back() + a[i]);
    }

    int Lsize = L.size(), Rsize = R.size();
    int ans = 1;
    rep(i,Lsize){
        ll rem = lim - L[i] * 2;
        if(rem < 0) break;
        rep(j,Rsize){
            if(rem - R[j] >= 0) ans = max(ans, i + j + 1);
        }
    }

    rep(i,Rsize){
        ll rem = lim - R[i] * 2;
        if(rem < 0) break;
        rep(j,Lsize){
            if(rem - L[j] >= 0) ans = max(ans, i + j + 1);
        }
    }

    cout << ans << endl;

    return 0;
}