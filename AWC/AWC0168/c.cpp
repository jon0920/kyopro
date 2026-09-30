#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    dsu uf(n);
    int cnt = 0;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(!uf.same(a, b)) uf.merge(a, b);
        else cnt++;
    }

    cout << (cnt > k ? "No" : "Yes") << endl;
    
    return 0;
}