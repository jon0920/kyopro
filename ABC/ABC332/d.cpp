#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> A(h, vector<int>(w));
    vector<vector<int>> B(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> A[i][j];
    rep(i,h) rep(j,w) cin >> B[i][j];

    vector<int> x(h), y(w);
    iota(x.begin(), x.end(), 0);
    iota(y.begin(), y.end(), 0);

    int ans = 1e9;
    do{
        do{
            bool ok = true;
            rep(i,h){
                rep(j,w){
                    if(A[x[i]][y[j]] != B[i][j]){
                        ok = false;
                    }
                }
            }            
            if(ok){
                int cnt = 0;
                rep(i,h) rep(j,h) if(i < j && x[i] > x[j]) cnt++;
                rep(i,w) rep(j,w) if(i < j && y[i] > y[j]) cnt++;
                ans = min(ans, cnt);
            }
        }while(next_permutation(y.begin(), y.end()));
    }while(next_permutation(x.begin(), x.end()));

    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}