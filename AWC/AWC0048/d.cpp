#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int sum2d(int xi, int yi, int xf, int yf, vector<vector<int>> &s){
    int res = 0;
    res += s[xf][yf];
    res -= s[xi - 1][yf];
    res -= s[xf][yi - 1];
    res += s[xi - 1][yi - 1];
    return res;
}

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> sum(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            sum[i][j] = s[j - 1] - '0';
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) sum[i][j] += sum[i][j - 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) sum[i][j] += sum[i - 1][j];
    }

    vector<pair<int,int>> p;
    for(int x = 1; x <= 200; x++){
        if(k % x == 0 && (k / x) <= 200) p.push_back({x, k / x});
    }

    int ans = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(auto &[xi, yi] : p){
                int xf = i + xi - 1;
                int yf = j + yi - 1;
                if(xf <= n && yf <= m){
                    ans = max(ans, sum2d(i, j, xf, yf, sum));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}