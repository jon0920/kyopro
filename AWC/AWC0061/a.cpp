#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> cnt(m);
    rep(i,n){
        int k;
        cin >> k;
        rep(j,k){
            int c;
            cin >> c;
            c--;
            cnt[c]++;
        }
    }

    int ans = 0;
    for(auto x : cnt) if(x == n) ans++;
    cout << ans << endl;

    return 0;
}