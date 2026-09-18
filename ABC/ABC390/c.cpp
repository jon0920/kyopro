#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int hmin = 1001, hmax = 0, wmin = 1001, wmax = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                hmin = min(hmin, i);
                hmax = max(hmax, i);
                wmin = min(wmin, j);
                wmax = max(wmax, j);
            }
        }
    }

    for(int i = hmin; i <= hmax; i++){
        for(int j = wmin; j <= wmax; j++){
            if(s[i][j] == '.'){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}