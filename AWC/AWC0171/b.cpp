#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    int ans = 0;
    int mx = 0;
    rep(i,h){
        string s;
        cin >> s;
        int cnt = 0;
        for(char c : s){
            if(c == '.') cnt++;
        }
        if(cnt > mx){
            ans = i;
            mx = cnt;
        }
    }
    cout << ans + 1 << endl;
    
    return 0;
}