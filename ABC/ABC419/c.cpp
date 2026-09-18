#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> r(n), c(n);
    int min_r = 1e9, max_r = 0, min_c = 1e9, max_c = 0;
    rep(i,n){
        cin >> r[i] >> c[i];
        min_r = min(min_r, r[i]);
        max_r = max(max_r, r[i]);
        min_c = min(min_c, c[i]);
        max_c = max(max_c, c[i]);
    }

    int mid_r = (min_r + max_r) / 2;
    int mid_c = (min_c + max_c) / 2;

    int ans = 0;
    rep(i,n){
        int dist = max(abs(r[i] - mid_r), abs(c[i] - mid_c));
        ans = max(ans, dist);
    }

    cout << ans << endl;
    
    return 0;
}