#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    int l = -1, r = -1;

    vector<bool> check1(3), check2(3);
    rep(i,n){
        check1[s[i] - 'A'] = true;
        if(check1[0] && check1[1] && check1[2]){
            l = i + 1;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        check2[s[i] - 'A'] = true;
        if(check2[0] && check2[1] && check2[2]){
            r = i;
            break;
        }
    }

    if(l >= r){
        cout << 0 << endl;
        return 0;
    }

    vector<int> nxt(3, INF);
    ll ans = 0;
    for(int i = n - 1; i >= l; i--){
        nxt[s[i] - 'A'] = i;
        int last = *max_element(nxt.begin(), nxt.end());
        if(last + 1 <= r){
            ans += r - last;
        }
    }

    cout << ans << endl;
    
    return 0;
}