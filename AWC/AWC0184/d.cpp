#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, w, k;
    cin >> n >> w >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int ans = 1e9;
    for(int bit = 0; bit < (1 << (n - w + 1)); bit++){
        if(__builtin_popcount(bit) > k) continue;
        vector<int> tmp = h;
        rep(i,n - w + 1){
            if((bit >> i) & 1){
                for(int j = i; j < i + w; j++){
                    tmp[j] = 0;
                }
            }
        }
        int sum = 0;
        rep(i,n) sum += tmp[i];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    
    return 0;
}