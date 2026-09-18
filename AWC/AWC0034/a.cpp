#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    int ans = 0;
    rep(i,m){
        int t;
        cin >> t;
        t--;
        if(c[t] > 0){
            ans++;
            c[t]--;
        }
    }
    cout << ans << endl;

    return 0;
}