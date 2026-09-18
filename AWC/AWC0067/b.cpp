#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){

    int n;
    cin >> n;
    ll ans = -INF;
    ll sum = 0, sum_min = 0;
    rep(i,n){
        ll b;
        cin >> b;
        sum += b;
        ans = max(ans, sum - sum_min);
        sum_min = min(sum_min, sum);
        cout << ans << endl;
    }

    return 0;
}