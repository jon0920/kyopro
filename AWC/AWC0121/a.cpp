#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    int D = 0;
    rep(i,n){
        int d;
        cin >> d;
        D = max(d, D);
    }

    int ans = 0;
    rep(i,m){
        string s;
        int h;
        cin >> s >> h;
        if(h > D) ans++;
    }
    cout << ans << endl;
    
    return 0;
}