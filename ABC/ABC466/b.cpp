#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> color(m, -1);

    rep(i,n){
        int c, s;
        cin >> c >> s;
        c--;
        color[c] = max(color[c], s);
    }

    for(auto x : color) cout << x << " ";
    cout << endl;
    return 0;
}