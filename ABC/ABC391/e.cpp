#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){

    int n;
    string s;
    cin >> n >> s;
    int sz = 1;
    rep(i,n) sz *= 3;
    vector<pair<int,int>> a(sz, {-1, 1});
    rep(i,sz) a[i].first = s[i] - '0';

    vector<vector<pair<int,int>>> na(n + 1);
    na[0] = a;
    int m = sz;
    for(int i = 1; i <= n; i++){
        m /= 3;
        na[i].resize(m);
        rep(j,m){
            int zero = 0, one = 0;
            vector<vector<int>> change_cnt(2);
            rep(k,3){
                auto [x, y] = na[i - 1][j * 3 + k];
                if(x == 0){
                    zero++;
                    change_cnt[0].push_back(y);
                }
                else{
                    one++;
                    change_cnt[1].push_back(y);
                }
            }
            sort(change_cnt[0].begin(), change_cnt[0].end());
            sort(change_cnt[1].begin(), change_cnt[1].end());
            int cnt = 0;
            if(zero < one){
                one--;
                rep(l,one) cnt += change_cnt[1][l];
                na[i][j] = {1, cnt};
            } else {
                zero--;
                rep(l,zero) cnt += change_cnt[0][l];
                na[i][j] = {0, cnt};
            }
        }
    }

    cout << na[n][0].second << endl;

    return 0;
}