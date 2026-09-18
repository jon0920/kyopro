#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int ans = 0;
    int mx = 0;
    for(int i = n - 1; i >= 0; i--){
        if(mx <= h[i]){
            ans++;
            mx = h[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}