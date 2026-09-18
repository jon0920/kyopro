#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    rep(i,n) cin >> r[i];
    int ans = 0;
    rep(i,m){
        int f, s;
        cin >> f >> s;
        if(r[f - 1] >= s){
            ans++;
            r[f - 1] -= s;
        }
    }

    cout << ans << endl;
    
    return 0;
}