#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;

    vector<int> imos(n + 1);
    rep(i,n){
        if(s[i] == 'o'){
            imos[0]++;
            imos[i + 1]--;
        }
    }
    rep(i,n) imos[i + 1] += imos[i];

    int l = 0, r = n - 1;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        if(imos[i] % 2 == 0){
            ans[r] = i + 1;
            r--;
        } else {
            ans[l] = i + 1;
            l++;
        }
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}