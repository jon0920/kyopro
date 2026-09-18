#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, c;
    cin >> n >> c;
    vector<int> t(n);
    rep(i,n) cin >> t[i];

    int prev = -10000;
    int ans = 0;
    rep(i,n){
        if(t[i] - prev >= c){
            ans++;
            prev = t[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}