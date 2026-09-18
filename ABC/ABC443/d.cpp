#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n){
            cin >> a[i];
        }
        
        vector<int> l(n), r(n);

        l[0] = a[0];
        for(int i = 1; i < n; i++){
            l[i] = min(a[i], l[i - 1] + 1);
        }

        r[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--){
            r[i] = min(a[i], r[i + 1] + 1);
        }

        ll ans = 0;
        rep(i,n){
            int x = min(l[i], r[i]);
            ans += (a[i] - x);
        }
        cout << ans << endl;
        
    }
    
    return 0;
}