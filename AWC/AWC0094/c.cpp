#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    sort(x.begin(), x.end());
    ll max_dist = x.back() - x.front();
    ll dist_sum = 0;
    for(int i = 1; i < n - 1; i++){
        dist_sum += x[i + 1] - x[i - 1];
    }

    cout << min(max_dist * 2, dist_sum + max_dist) << endl;
    
    return 0;
}