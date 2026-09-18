#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];

    int ans = 0;
    rep(i,n){
        if(s[i] == 1) continue;

        bool ok = true;
        if(i - 2 >= 0 && (s[i - 2] == 1 && s[i - 1] == 1)) ok = false;
        if((i - 1 >= 0 && i + 1 < n) && (s[i - 1] == 1 && s[i + 1] == 1)) ok = false;
        if(i + 2 < n && (s[i + 1] == 1 && s[i + 2] == 1)) ok = false;

        if(ok){
            ans++;
            s[i] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}