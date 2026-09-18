#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    sort(s.begin(), s.end());

    ll ans = 0;
    do{
        for(int i = 1; i < n; i++){
            string t = s.substr(0, i);
            string r = s.substr(i);
            if(t[0] == '0' || r[0] == '0') continue;
            ll x = stoll(t), y = stoll(r);
            ans = max(ans, x * y);
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    
    return 0;
}