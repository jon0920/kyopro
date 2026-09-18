#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    vector<int> ba;
    for(auto x : b) ba.push_back(x);
    for(auto x : a) ba.push_back(x);
    n = ba.size();

    vector<int> z(n);
    int c = 0;
    for(int i = 1; i < n; i++){
        if(i + z[i - c] < c + z[c]){
            z[i] = z[i - c];
        } else {
            int j = max(0, c + z[c] - i);
            while(i + j < n && ba[j] == ba[i + j]) j++;
            z[i] = j;
            c = i;
        }
    }
    z[0] = n;

    for(int i = m; i < n; i++) if(z[i] >= m){
        cout << i + 1 - m << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}