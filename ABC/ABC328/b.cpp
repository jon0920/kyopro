#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        for(int j = 1; j <= d[i - 1]; j++){
            bool ok = true;
            string t = to_string(j);
            string x = s + t;
            rep(i,x.size()){
                if(x[i] != x[0]) ok = false;
            }
            if(ok) ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}