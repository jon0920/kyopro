#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> p(n - 1);
    rep(i,n - 1) cin >> p[i], p[i]--;

    int now = 0;
    int ans = 1;
    while(now != n - 1){
        ans++;
        now = p[now];
    }

    cout << ans << endl;

    return 0;
}