#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    sort(x.begin(), x.end());
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans = max(ans, x[i + 1] - x[i]);
    }
    cout << ans << endl;

    return 0;
}