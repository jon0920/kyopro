#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

int main(){
    
    string n;
    int k, r;
    cin >> n;
    int m = n.size();
    cin >> k >> r;
    if(k != 1) cout << 0 << endl;
    else{
        mint ans = 0;
        rep(i,m){
            ans = ans * 10 + (n[i] - '0');
        }
        ans -= 2;
        cout << ans.val() << endl;
    }
    
    return 0;
}