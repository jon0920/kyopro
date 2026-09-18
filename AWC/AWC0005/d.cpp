#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

bool solve(vector<ll> a, int k, ll mid){
    ll w = 0, cnt = 0;
    for(ll x : a){
        w += x;
        if(w >= mid){
            cnt++;
            w = 0;
        }
    }
    return cnt >= k;
}

int main(){

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    ll ok = 0, ng = sum + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(solve(a, k, mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}