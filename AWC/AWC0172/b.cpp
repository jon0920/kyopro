#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    int mx = 0;
    rep(i,h){
        string s;
        cin >> s;
        int cnt = 0;
        for(char c : s){
            if(c == 'x') cnt++;
        }
        mx = max(mx, cnt);
    }

    cout << mx << endl;
    
    return 0;
}