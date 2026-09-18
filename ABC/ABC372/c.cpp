#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<bool> check(n);
    int ans = 0;
    for(int i = 0; i < n - 2; i++){
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') ans++;
    }

    rep(i,q){
        int x;
        char c;
        cin >> x >> c;
        x--;
        rep(k,3){
            int pos = x - k;
            if(pos >= 0 && pos < n){
                if(s[pos] == 'A' && s[pos + 1] == 'B' && s[pos + 2] == 'C') ans--;
            }
        }
        s[x] = c;
        rep(k,3){
            int pos = x - k;
            if(pos >= 0 && pos < n){
                if(s[pos] == 'A' && s[pos + 1] == 'B' && s[pos + 2] == 'C') ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}