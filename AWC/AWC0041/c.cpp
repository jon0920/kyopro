#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    rep(i,n){
        int it = a.end() - lower_bound(a.begin(), a.end(), k - a[i]);
        int sum = min(it, n - i - 1);
        ans += sum;
    }
    cout << ans << endl;

    return 0;
}