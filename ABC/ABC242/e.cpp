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

        mint res = 0;
        rep(i,mid){
            res = res * 26 + (s[i] - 'A');
        }

        string t = s;
        rep(i,mid){
            t[n - i - 1] = t[i];
        }
        if(t <= s) res++;

        cout << res.val() << endl;
    }
    
    return 0;
}