#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    rep(i,n){
        bool ok = true;
        for(char c : s[i]){
            if(c != 'x') ok = false;
        }
        if(ok){
            cout << "Faucet " << i + 1 << endl;
            return 0;
        }
    }

    rep(i,m){
        bool ok = true;
        rep(j,n){
            if(s[j][i] != 'x') ok = false;
        }
        if(ok){
            cout << "Drain " << i + 1 << endl;
            return 0;
        }
    }

    
    return 0;
}