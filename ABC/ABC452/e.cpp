#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main(){
    int N, M;
    cin >> N >> M;

    vector<ll> A(N+1), B(M+1);
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int j = 1; j <= M; j++) cin >> B[j];

    // prefix sum
    vector<ll> pref(N+1, 0);
    for(int i = 1; i <= N; i++){
        pref[i] = (pref[i-1] + A[i]) % MOD;
    }

    // Σ A[i]*i
    ll sum_iA = 0;
    for(int i = 1; i <= N; i++){
        sum_iA = (sum_iA + A[i] * i) % MOD;
    }

    ll ans = 0;

    for(int j = 1; j <= M; j++){
        ll Sj = sum_iA;

        ll sub = 0;

        for(ll k = 1; k * j <= N; k++){
            ll l = k * j;
            ll r = min((ll)N, (k+1)*j - 1);

            ll s = (pref[r] - pref[l-1] + MOD) % MOD;
            sub = (sub + k * s) % MOD;
        }

        Sj = (Sj - j % MOD * sub % MOD + MOD) % MOD;

        ans = (ans + B[j] % MOD * Sj % MOD) % MOD;
    }

    cout << ans << endl;
}