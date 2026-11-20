#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;

    ll ans = 0;
    for(int i = 0; i < k; i++){
        bool ok = true;
        for(int j = i; j < n; j += k){
            if(j >= k && t[j - k] == t[j] && !ok) ok = true;
            else{
                if(t[j] == 'r') ans += p;
                else if(t[j] == 's') ans += r;
                else ans += s;
                ok = false;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}