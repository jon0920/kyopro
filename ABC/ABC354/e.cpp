#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for(int s = 0; s < (1 << n); s++){
        bool ok = false;
        rep(i,n){
            for(int j = i + 1; j < n; j++){
                if(((s >> i) & 1) && ((s >> j) & 1)){
                    if((a[i] == a[j] || b[i] == b[j]) && dp[s ^ (1 << i) ^ (1 << j)] == 0){
                        ok = true;
                    }
                }
            }
        }
        dp[s] = ok;
    }

    cout << (dp[(1 << n) - 1] ? "Takahashi" : "Aoki") << endl;
    
    return 0;
}