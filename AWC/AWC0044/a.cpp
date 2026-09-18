#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m;
    cin >> n >> m;
    rep(i,n){
        ll c, s;
        cin >> c >> s;
        ll d = min(c - s, m);
        cout << s + d << endl;
        m -= d;
    }

    return 0;
}