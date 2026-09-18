#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<set<string>> w(n);
    rep(i,n){
        int m;
        cin >> m;
        rep(j,m){
            string s;
            cin >> s;
            w[i].insert(s);
        }
    }
    
    int ans = 0;
    rep(i,n - 1){
        for(int j = i + 1; j < n; j++){
            int cnt = 0;
            for(auto t : w[i]){
                if(w[j].count(t)) cnt++;
            }
            if(cnt >= k) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}