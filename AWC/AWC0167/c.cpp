#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    int cnt = 1;
    ll dist = 0;
    ll sum = 0;
    rep(i,m - 1){
        ll d;
        cin >> d;
        sum += d;
        dist += d;
        if(dist >= k){
            cnt++;
            dist = 0;
        }
    }

    if(cnt >= n) cout << (n == 1 ? 0 : sum) << endl;
    else cout << -1 << endl;
    
    return 0;
}