#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int ans = 0;
    for(int i1 = 0; i1 < h; i1++){
        for(int j1 = 0; j1 < w; j1++){
            if(s[i1][j1] == '#') continue;

            for(int i2 = 0; i2 < h; i2++){
                for(int j2 = 0; j2 < w; j2++){
                    if((i1 == i2 && j1 == j2) || s[i2][j2] == '#') continue;
                    int cnt = 0;
                    for(int i3 = 0; i3 < h; i3++){
                        for(int j3 = 0; j3 < w; j3++){
                            if(s[i3][j3] == '.' && ((abs(i1 - i3) + abs(j1 - j3)) <= d || ((abs(i2 - i3) + abs(j2 - j3)) <= d))) cnt++; 
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}