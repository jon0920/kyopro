#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    vector<string> s(5);
    rep(i,5) cin >> s[i];

    int ans = 5;
    rep(i,5){
        int cnt = 0;
        for(char c : s[i]) if(c == '.') cnt++;
        ans = min(ans, cnt);
    }

    rep(i,5){
        int cnt = 0;
        rep(j,5){
            if(s[j][i] == '.') cnt++;
        }
        ans = min(ans, cnt);
    }

    int d1 = 0;
    int d2 = 0;
    rep(i,5){
        if(s[i][i] == '.') d1++;
        if(s[i][4 - i] == '.') d2++;
    }

    cout << min({ans, d1, d2}) << endl;
    
    return 0;
}