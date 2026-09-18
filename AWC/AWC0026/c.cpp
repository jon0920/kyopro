#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, t, e;
    cin >> n >> t >> e;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    sort(p.begin(), p.end());

    ll sum = 0, cnt = 0;
    rep(i,n){
        if(sum + p[i] * t <= e){
            cnt++;
            sum += p[i] * t;
        }
        else break;
    }
    cout << cnt << endl;

    return 0;
}