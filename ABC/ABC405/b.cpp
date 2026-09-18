#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    bool flag = 1;
    int ans = 0;
    while(flag){
        vector<bool> c(m, 0);
        rep(i,n){
            c[a[i] - 1] = 1;
        }
        n--;
        rep(i,m){
            if(c[i] == 0){
                cout << ans << endl;
                return 0;
            }
        }
        ans++;
    }
    
    return 0;
}