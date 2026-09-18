#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, l, q;
    cin >> n >> l >> q;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    rep(i,q){
        int m;
        cin >> m;
        string res = "";
        rep(j,m){
            int c;
            cin >> c;
            c--;
            if(j == 0){
                rep(k,l){
                    res += s[c][k];
                }
            } else {
                rep(k,l){
                    if(s[c][k] == '1' || res[k] == '1') res[k] = '1';
                    else res[k] = '0';
                }
            }
        }
        cout << res << endl;
    }
    
    return 0;
}