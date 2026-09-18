#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    n--;
    ll d = 1;
    int k;
    bool odd = false;
    for(ll i = 1; i <= 36; i++){
        if(i / 2 >= 1 && i % 2 == 1){
            d *= 10;
        }
        if(n - d * 9 <= 0){
            if(i % 2 == 1) odd = true;
            k = (i + 1) / 2;
            break;
        } else {
            n -= d * 9;
        }
    }

    ll m = 1;
    rep(i,k - 1) m *= 10;
    m += n - 1;

    string s = to_string(m);
    string t = s;
    if(odd) t.pop_back();
    reverse(t.begin(), t.end());

    cout << s + t << endl;
    
    return 0;
}