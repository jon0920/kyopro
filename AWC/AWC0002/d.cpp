#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> c(n), r(m);
    rep(i,n) cin >> c[i];
    rep(i,m) cin >> r[i];

    sort(c.begin(), c.end());
    sort(r.begin(), r.end());

    int ans = 0;
    int pos = 0, key = 0;
    while(pos < n && key < m){
        if(c[pos] <= r[key]){
            ans++; pos++; key++;
        }
        else{
            key++;
        }
    }

    cout << ans << endl;

    return 0;
}