#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;

    map<ll,ll> memo;
    auto solve = [&](auto solve, ll x){
        if(x == 0) return 1LL;
        if(memo.count(x)) return memo[x];

        ll fx = solve(solve, x/2) + solve(solve, x/3);
        memo[x] = fx;
        return fx;
    };

    cout << solve(solve, n) << endl;
    
    
    return 0;
}