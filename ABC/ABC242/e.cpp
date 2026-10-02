#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        int mid = (n + 1) / 2;

        mint ans = 0;
        rep(i,mid){
            ans = ans * 26 + (s[i] - 'A');
        }

        string x = s;
        rep(i,mid){
            x[n - i - 1] = s[i];
        }

        if(x <= s) ans++;

        cout << ans.val() <<endl;
    }
    
    return 0;
}