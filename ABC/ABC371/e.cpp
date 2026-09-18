#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

int main(){

    ll n;
    cin >> n;

    vector<vector<int>> pos(n + 1);
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        pos[a].push_back(i);
    }

    ll total = n * (n + 1) / 2;
    ll ans = 0;
    for(int x = 1; x <= n; x++){
        ll d = 0;
        int last = 0;
        for(int p : pos[x]){
            ll L = p - last - 1;
            d += L * (L + 1) / 2;
            last = p;
        }

        ll L = n - last;
        d += L * (L + 1) / 2;

        ans += total - d;
    }

    cout << ans << endl;

    return 0;
}