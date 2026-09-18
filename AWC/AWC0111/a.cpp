#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    rep(i,n){
        vector<int> s(m);
        rep(j,m){
            cin >> s[j];
        }
        sort(s.begin(), s.end());
        int sum = 0;
        if(m >= 3){
            for(int i = 1; i < m - 1; i++) sum += s[i];
            if(sum / (m - 2) < k) ans++;
        } else {
            rep(i,m) sum += s[i];
            if(sum / m < k) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}