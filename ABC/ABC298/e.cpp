#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    vector<vector<mint>> tdp(n - a + 1, vector<mint>(n + 1));
    vector<vector<mint>> adp(n - b + 1, vector<mint>(n + 1));

    tdp[0][a] = 1;
    adp[0][b] = 1;

    for(int turn = 0; turn < n - a; turn++){
        rep(i,n){
            if(tdp[turn][i] == 0) continue;
            for(int j = 1; j <= p; j++){
                tdp[turn + 1][min(n, i + j)] += tdp[turn][i];
            }
        }
    }

    return 0;
}