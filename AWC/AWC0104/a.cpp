#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.rbegin(), a.rend());
    if(a.size() >= 2 && a[0].first == a[1].first) cout << -1 << endl;
    else cout << a[0].second << endl;
    
    return 0;
}