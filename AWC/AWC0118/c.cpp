#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    const string t = "ATCODER";

    int ans = 0, cut = 0;
    rep(i,n - 6){
        if(s.substr(i,7) == t){
            if(i == 0 && i + 7 == n);
            else if(i == 0 || i + 7 == n) cut++;
            else cut += 2;

            if(cut > m) break;
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}