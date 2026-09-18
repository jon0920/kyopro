#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> p(2, vector<int>(n));
    rep(i,n){
        int x = a[i];
        while(x % 2 == 0){
            p[0][i]++;
            x /= 2;
        }
        while(x % 3 == 0){
            p[1][i]++;
            x /= 3;
        }
        a[i] = x;
    }

    rep(i,n){
        if(a[0] != a[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    int min_p0 = *min_element(p[0].begin(), p[0].end());
    int min_p1 = *min_element(p[1].begin(), p[1].end());
    ll ans = 0;
    rep(i,n){
        ans += p[0][i] - min_p0;
        ans += p[1][i] - min_p1;
    }
    
    cout << ans << endl;
    
    return 0;
}