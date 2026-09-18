#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int N, W;
        cin >> N >> W;

        vector<ll> C(N);
        for(int i = 0; i < N; i++) cin >> C[i];

        vector<ll> a(2*W, 0);

        for(int i = 0; i < N; i++){
            a[i % (2*W)] += C[i];
        }

        vector<ll> b = a;
        b.insert(b.end(), a.begin(), a.end());

        ll sum = 0;
        for(int i = 0; i < W; i++) sum += b[i];

        ll ans = sum;

        for(int i = W; i < 4*W; i++){
            sum += b[i];
            sum -= b[i-W];
            ans = min(ans, sum);
        }

        cout << ans << '\n';
    }
}