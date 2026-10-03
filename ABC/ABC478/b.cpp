#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, v;
    cin >> n >> v;
    vector<int> w(n);
    rep(i,n) cin >> w[i];

    int ans = 0;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            rep(k,n){
                if(i == k || j == k) continue;
                if(i + j + k + 3 > v) continue;
                ans = max(ans, w[i] + w[j] + w[k]);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}