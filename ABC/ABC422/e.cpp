#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<ll,ll>> point(n);
    rep(i,n) cin >> point[i].first >> point[i].second;

    mt19937 rng(58);

    rep(_,100){
        int i = rng() % n;
        int j = rng() % n;
        while(i == j){
            i = rng() % n;
        }

        auto [xi, yi] = point[i];
        auto [xj, yj] = point[j];

        ll a = yi - yj;
        ll b = xj - xi;
        ll c = xi * yj - xj * yi;

        int cnt = 0;
        rep(i,n){
            auto [x, y] = point[i];
            if(a * x + b * y + c == 0) cnt++;
        }
        if(cnt * 2 > n){
            cout << "Yes" << endl;
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}