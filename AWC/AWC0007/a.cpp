#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    ll mn = 1e9;
    rep(i,n){
        ll e;
        cin >> e;
        mn = min(mn, e);
    }

    ll sum = 0;
    rep(i,m){
        ll c;
        cin >> c;
        sum += c;
    }
    cout << mn * sum << endl;

    return 0;
}