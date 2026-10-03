#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> score(n);
    rep(i,n){
        ll h, s, d;
        cin >> h >> s >> d;
        score[i] = h + s;
    }

    ll mx = *max_element(score.begin(), score.end());
    rep(i,n){
        if(score[i] == mx){
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    return 0;
}