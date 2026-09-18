#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    vector<int> rotate(n);
    rep(i,n){
        int pos = (i - p[i] + n) % n;
        rotate[pos]++;
        rotate[(pos + 1) % n]++;
        rotate[(pos - 1 + n) % n]++;
    }

    int ans = 0;
    for(auto x : rotate) ans = max(ans, x);
    cout << ans << endl;

    return 0;
}