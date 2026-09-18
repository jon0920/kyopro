#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    vector<vector<string>> p(3, vector<string>(4));
    int total = 0;
    rep(i,3){
        rep(j,4){
            cin >> p[i][j];
            for(char c : p[i][j]) if(c == '#') total++;
        }
    }

    if(total != 16){
        cout << "No" << endl;
        return 0;
    }

    auto rotate = [&](vector<string> &s) -> void {
        vector<string> res = s;
        rep(i,4) rep(j,4) res[j][3 - i] = s[i][j];
        s = res;
    };

    vector<vector<int>> masks(3);
    rep(i,3){
        vector<string> cur = p[i];
        rep(r,4){
            for(int dx = -3; dx <= 3; dx++){
                for(int dy = -3; dy <= 3; dy++){
                    bool ok = true;
                    int mask = 0;
                    rep(x,4){
                        rep(y,4){
                            if(cur[x][y] == '#'){
                                int nx = x + dx;
                                int ny = y + dy;
                                if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4) mask |= (1 << (nx * 4 + ny));
                                else ok = false;
                            }
                        }
                    }
                    if(ok) masks[i].push_back(mask);
                }
            }
            rotate(cur);
        }
    }

    for(int x0 : masks[0]){
        for(int x1 : masks[1]){
            for(int x2 : masks[2]){
                if((x0 & x1) == 0 && (x1 & x2) == 0 && (x2 & x0) == 0){
                    if((x0 | x1 | x2) == 0xFFFF){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    
    return 0;
}