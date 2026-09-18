#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt = 0;
    int ans = 0;
    rep(i,n){
        if(s[i] == 'O'){
            cnt++;
            if(cnt == k){
                ans++;
                cnt = 0;
            }
        }
        else cnt = 0;
    }
    
    cout << ans << endl;
    
    return 0;
}