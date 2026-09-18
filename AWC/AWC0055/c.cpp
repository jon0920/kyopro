#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> w(n), c(n);
    rep(i,n) cin >> w[i];
    rep(i,n) cin >> c[i];
    sort(w.rbegin(), w.rend());
    sort(c.rbegin(), c.rend());

    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < n){
        if(w[i] <= c[j]){
            ans++;
            i++, j++;
        } else i++;
    }

    cout << ans << endl;

    return 0;
}