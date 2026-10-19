#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<int,int>> p;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        p.push_back({a, i});
    }

    sort(p.begin(), p.end());

    for(auto [x, y] : p) cout << y << " ";
    cout << endl;
    
    return 0;
}