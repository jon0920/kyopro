#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){
    
    int n, m;
    cin >> n >> m;

    mint M = m - 1;
    mint ans = M.pow(n);

    if(n % 2 == 0) ans += m - 1;
    else ans -= m - 1;

    cout << ans.val() << endl;
    
    return 0;
}