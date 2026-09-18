#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    ll ans = 0;
    int ra = 0, rb = 0;
    int a_cnt = 0, b_cnt = 0;
    for(int l = 0; l < n; l++){
        while(ra < n && a_cnt < a){
            if(s[ra] == 'a') a_cnt++;
            ra++;
        }
        if(ra == n && a_cnt < a) ra++;
        while(rb < n && b_cnt < b){
            if(s[rb] == 'b') b_cnt++;
            rb++;
        }
        if(rb == n && b_cnt < b) rb++;

        ans += max(0, rb - ra);

        if(s[l] == 'a') a_cnt--;
        else b_cnt--;
    }

    cout << ans << endl;
    
    return 0;
}