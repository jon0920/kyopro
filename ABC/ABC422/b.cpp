#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h + 2, vector<char>(w + 2, '.'));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++) cin >> c[i][j];
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(c[i][j] == '#'){
                int cnt = 0;
                if(c[i - 1][j] == '#') cnt++;
                if(c[i + 1][j] == '#') cnt++;
                if(c[i][j - 1] == '#') cnt++;
                if(c[i][j + 1] == '#') cnt++;
                if(cnt != 2 && cnt != 4){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}