#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    dsu uf(n * 2 + 1);
    for(int i = 1; i <= n; i++){
        uf.merge(i * 2, i * 2 - 1);
    }

    int loop = 0;
    rep(i,m){
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a *= 2, c *= 2;
        if(b == 'R') a--;
        if(d == 'R') c--;

        if(uf.same(a,c)) loop++;
        uf.merge(a,c);
    }

    int cnt = 0;
    for(int i = 1; i <= n * 2; i++){
        if(uf.leader(i) == i) cnt++;
    }

    cout << loop << " " << cnt - loop << endl;

    return 0;
}