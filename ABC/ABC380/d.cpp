#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string s;
    int q;
    cin >> s >> q;
    ll n = s.size();
    ll m = n;
    vector<ll> len;
    while(m < 1e18){
        len.push_back(m);
        m *= 2;
    }

    while(q--){
        ll k;
        cin >> k;
        k--;
        int cnt = 0;
        while(k >= n){
            auto it = upper_bound(len.begin(), len.end(), k);
            it--;
            k -= *it;
            cnt++;
        }
        if(cnt % 2 == 0) cout << s[k] << " ";
        else{
            if(islower(s[k])) cout << (char)toupper(s[k]) << " ";
            else cout << (char)tolower(s[k]) << " ";
        }
    }
    cout << endl;

    return 0;
}