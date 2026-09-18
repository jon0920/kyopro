#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    k--;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    auto solve = [&](ll x) -> bool {
        int cnt = 0;
        ll len = 0;
        rep(i,n){
            if(len + a[i] > x){
                cnt++;
                len = 0;
            }
            len += a[i];
        }
        return cnt <= k;
    };

    ll ng = *max_element(a.begin(), a.end()) - 1;
    ll ok = 1e15;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}