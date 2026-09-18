#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    vector<int> imos(n + 1);
    rep(i,n){
        if((s[i] == '0') ^ (imos[i] % 2 == 1)){
            if(i + k > n){
                cout << -1 << endl;
                return 0;
            }
            ans++;
            imos[i]++;
            imos[i + k]--;
        }
        imos[i + 1] += imos[i];
    }

    cout << ans << endl;

    return 0;
}