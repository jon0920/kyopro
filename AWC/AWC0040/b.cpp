#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int m, s;
    cin >> m >> s;
    vector<ll> b(m);
    rep(i,m) cin >> b[i];
    int q = s / m, r = s % m;
    rep(i,m){
        if(i < r) b[i]++;
        b[i] += q;
    }

    vector<ll> sum(m + 1);
    for(int i = 1; i <= m; i++){
        sum[i] = sum[i - 1] + b[i - 1];
    }

    int n;
    cin >> n;
    while(n--){
        int l, r;
        cin >> l >> r;
        l--;
        cout << sum[r] - sum[l] << endl;
    }

    return 0;
}