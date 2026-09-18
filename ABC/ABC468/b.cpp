#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int m, d;
    cin >> m >> d;
    string s;
    cin >> s;
    vector<bool> check(m);
    rep(i,m){
        if(s[i] == 'G'){
            check[i] = true;
            int left = i, right = i;
            rep(j,d){
                left--; right++;
                if(left >= 0) check[left] = true;
                if(right < m) check[right] = true;
            }
        }
    }

    int ans = 0;
    rep(i,m) if(!check[i]) ans++;
    cout << ans << endl;
    
    return 0;
}