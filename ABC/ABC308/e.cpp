#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;

    map<pair<int,char>,ll> left, right;
    rep(i,n) right[{a[i], s[i]}]++;

    ll ans = 0;
    rep(i,n){
        if(s[i] == 'E'){
            rep(x,3){
                rep(y,3){
                    vector<bool> used(4);
                    used[a[i]] = true;
                    used[x] = true;
                    used[y] = true;
                    rep(j,4){
                        if(!used[j]){
                            ans += j * left[{x, 'M'}] * right[{y, 'X'}];
                            break;
                        }
                    }
                }
            }
        }
        right[{a[i], s[i]}]--;
        left[{a[i], s[i]}]++;
    }

    cout << ans << endl;
    
    return 0;
}