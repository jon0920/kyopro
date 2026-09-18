#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    rep(i,m){
        int p, v;
        cin >> p >> v;
        p--;
        s[p] = v;
    }

    int ans = 0;
    for(int x : s){
        if(x < k) ans++;
    }
    cout << ans << endl;

    return 0;
}