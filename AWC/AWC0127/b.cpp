#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<bool> is_same(n - 1);
    int cnt = 0;
    rep(i,n - 1){
        if(s[i] == s[i + 1]){
            is_same[i] = true;
            cnt++;
        }
    }

    auto check = [&](int x, int y) -> void {
        if(x < 0 || y >= n) return;
        if(s[x] == s[y] && !is_same[x]){
            is_same[x] = true;
            cnt++;
            return;
        }
        if(s[x] != s[y] && is_same[x]){
            is_same[x] = false;
            cnt--;
            return;
        }
    };

    rep(qi,q){
        int i;
        char c;
        cin >> i >> c;
        i--;
        s[i] = c;
        check(i - 1, i);
        check(i, i + 1);
        cout << cnt << endl;
    }
    
    return 0;
}