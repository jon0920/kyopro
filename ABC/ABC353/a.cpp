#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int ans = -1;
    rep(i,n){
        if(h[0] < h[i]){
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}