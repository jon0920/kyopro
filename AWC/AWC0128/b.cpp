#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<char> w(n);
    rep(i,n) cin >> w[i];

    vector<int> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + (w[i] == 'S');

    int ans = 0;
    rep(i,n - k + 1){
        ans = max(ans, sum[i + k] - sum[i]);
    }
    cout << ans << endl;
    
    return 0;
}