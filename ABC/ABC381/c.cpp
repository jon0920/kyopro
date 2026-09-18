#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    rep(i,n){
        int cnt = 1;
        if(s[i] == '/'){
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < n){
                if(s[l] == '1' && s[r] == '2') cnt += 2;
                else break;
                l--; r++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}