#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> s;
    char c;
    rep(i,n){
        cin >> c;
        s.push_back(c - 'a');
    }
    sort(s.begin(), s.end());
    int ans = 0;
    bool ok, flag;

    while(true){
        ok = true;
        rep(i,n-k){
            flag = true;
            rep(j,k){
                if(s[i + j] != s[i + k - 1 - j]) flag = false;
            }
            if(flag) ok = false;
        }
        if(ok) ans++;
        if(!next_permutation(s.begin(), s.end())) break;
    }
    
    cout << ans << endl;
    return 0;
}