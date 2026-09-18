#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 2'000'000;
vector<bool> isp(M + 1, true);

void era(){
    isp[0] = false;
    isp[1] = false;
    for(int i = 2; pow(i, 2) <= M; i++){
        if(isp[i]) for(int j = 2; i * j <= M; j++) isp[i * j] = false;
    }
}

int main(){

    era();
    vector<ll> primes;
    rep(i,M) if(isp[i]) primes.push_back(i);
    int sz = primes.size();

    ll n;
    cin >> n;
    ll mx = 1;
    while((mx + 1) * (mx + 1) <= n) mx++;

    ll ans = 0;
    for(int i = 0; i < sz; i++){
        ll p = primes[i];
        if(p * p > mx) break;

        ll target = mx / p;
        auto it = upper_bound(primes.begin(), primes.end(), target);
        ans += distance(primes.begin() + i + 1, it);
    }

    for(ll p : primes){
        if(p > 37) break;
        if(p * p * p * p * p * p * p * p <= n) ans++;
    }

    cout << ans << endl;

    return 0;
}